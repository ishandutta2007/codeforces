#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<vector>
#include<algorithm>
using namespace std;

#define mod 1000000007
int add(int x,int y){
	return (x+=y)<mod?x:x-mod;
}
int mul(int x,int y){
	return (int)((long long int)x*y%mod);
}

#define ran 444444
int len;
char s[ran];
int p10[ran];

int chk_id[ran];

int nex_para[ran];
int pre_para[ran];
int nex_add[ran],nex_mul[ran];
int pre_add[ran],pre_mul[ran];
int st_pos[ran],st_chk_id[ran];
int top;int CHK;

int id[ran];
int typ[ran],T;
vector<int> op[ran];
int szz[ran];
int pos[ran];
int val[ran];
vector<int> seg[ran];

int CUR;
void build(int i,int s,int e){
	if(s==e){
		seg[CUR][i] = op[CUR][s];
		return;
	}
	int m=(s+e)/2;
	build(i*2,s,m);
	build(i*2+1,m+1,e);
	if(typ[CUR] == 2)
		seg[CUR][i] = add(seg[CUR][i*2],seg[CUR][i*2+1]);
	else
	if(typ[CUR] == 3)
		seg[CUR][i] = mul(seg[CUR][i*2],seg[CUR][i*2+1]);
	else
//	if(typ[CUR] == 4)
		seg[CUR][i] = add(mul(seg[CUR][i*2],p10[e-m]),seg[CUR][i*2+1]);
}
int query(int i,int s,int e,int l,int r){
	if(s==l && e==r)
		return seg[CUR][i];
	int m=(s+e)/2;
	if(r<=m)
		return query(i*2,s,m,l,r);
	if(l>m)
		return query(i*2+1,m+1,e,l,r);
	int res1 = query(i*2,s,m,l,m);
	int res2 = query(i*2+1,m+1,e,m+1,r);
	if(typ[CUR] == 2)
		return add(res1,res2);
	else
	if(typ[CUR] == 3)
		return mul(res1,res2);
	else
		return add(mul(res1,p10[r-m]),res2);
}

int analysis(int from, int to){
	int cur = ++T;
	if(s[from] == '(' && nex_para[from] == to){//This is (SAE)
		id[from] = id[to] = cur;
		typ[cur] = 1;
		return val[cur] = analysis(from+1,to-1);
	}
	if(nex_add[from] != -1 && nex_add[from] <= to){//This is SAE + SAE
		typ[cur] = 2;
		while(1){
			int nx = nex_add[from];
			if(nx == -1 || nx > to)break;
			op[cur].push_back(analysis(from, nx-1));
			id[nx] = cur;
			pos[nx] = op[cur].size();
			from = nx+1;
		}
		op[cur].push_back(analysis(from,to));
		int sz = szz[cur] = op[cur].size();
		seg[cur].resize(sz*4);
		CUR = cur;
		build(1,0,sz-1);
		return seg[cur][1];
	}
	if(nex_mul[from] != -1 && nex_mul[from] <= to){//This is SAE * SAE
		typ[cur] = 3;
		while(1){
			int nx = nex_mul[from];
			if(nx == -1 || nx > to)break;
			op[cur].push_back(analysis(from, nx-1));
			pos[nx] = op[cur].size();
			id[nx] = cur;
			from = nx+1;
		}
		op[cur].push_back(analysis(from,to));
		int sz = szz[cur] = op[cur].size();
		seg[cur].resize(sz*4);
		CUR = cur;
		build(1,0,sz-1);
		return seg[cur][1];
	}
	//This is number.
	typ[cur] = 4;
	for(int i=from; i<=to; i++){
		id[i] = cur;
		op[cur].push_back(s[i] - '0');
		pos[i] = op[cur].size();
	}
	int sz = szz[cur] = op[cur].size();
	seg[cur].resize(sz*4);
	CUR = cur;
	build(1,0,sz-1);
	return seg[cur][1];
}

int process(int from,int to){
	if(s[from] == '(' && nex_para[from] == to){
		return val[id[from]];
	}
	if(nex_add[from] != -1 && nex_add[from] <= to){
		int A = nex_add[from];
		int B = pre_add[to];
		int cur = id[A];
		int A_id = pos[A],B_id = pos[B];
		CUR = cur;
		int zz = A_id != B_id ? query(1,0,szz[cur]-1,A_id,B_id-1) : 0;
		zz = add(zz, process(from, A-1));
		zz = add(zz, process(B+1,to));
		return zz;
	}
	if(nex_mul[from] != -1 && nex_mul[from] <= to){
		int A = nex_mul[from];
		int B = pre_mul[to];
		int cur = id[A];
		int A_id = pos[A],B_id = pos[B];
		CUR = cur;
		int zz = A_id != B_id ? query(1,0,szz[cur]-1,A_id,B_id-1) : 1;
		zz = mul(zz, process(from, A-1));
		zz = mul(zz, process(B+1, to));
		return zz;
	}
	int cur = id[from];
	CUR = cur;
	return query(1,0,szz[cur]-1,pos[from]-1,pos[to]-1);
}

int main(){
	scanf("%s",s+1);
	len = strlen(s+1);
	s[0] = '(';
	s[len+1] = ')';
	len += 2;

	top=0;
	for(int i=0; i<len; i++)
		if(s[i] == '('){
			st_pos[top] = i;
			st_chk_id[top] = ++CHK;
			top++;
		}
		else
		if(s[i] == ')'){
			int from = st_pos[top-1] + 1, to = i - 1, chk = st_chk_id[top-1];
			int add = -1, mul = -1;
			for(int j = from; j <= to; j++){
				pre_add[j] = add;
				pre_mul[j] = mul;
				chk_id[j] = chk;
				if(s[j] == '('){
					j = nex_para[j];
					pre_add[j] = add;
					pre_mul[j] = mul;
					chk_id[j] = chk;
				}else
				if(s[j] == '+')
					add = j;
				else
				if(s[j] == '*')
					mul = j;
			}

			add = mul = -1;
			for(int j = to; j >= from; j--){
				nex_add[j] = add;
				nex_mul[j] = mul;
				if(s[j] == ')'){
					j = pre_para[j];
					nex_add[j] = add;
					nex_mul[j] = mul;
				}else
				if(s[j] == '+')
					add = j;
				else
				if(s[j] == '*')
					mul = j;
			}

			nex_para[st_pos[top-1]] = i;
			pre_para[i] = st_pos[top-1];
			--top;
		}

	p10[0] = 1;
	for(int i=1; i<=len; i++)
		p10[i] = mul(p10[i-1],10);
	analysis(0,len-1);

	int q,from,to;
	for(scanf("%d",&q); q--;){
		scanf("%d%d",&from,&to);
		if(chk_id[from] == chk_id[to] && 
			(isdigit(s[from]) || s[from] == '(') &&
			(isdigit(s[to]) || s[to] == ')')){
				printf("%d\n",process(from,to));
		}else
			puts("-1");
	}
	return 0;
}