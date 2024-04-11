#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int L,n;
char s[1111];int ls;
char a[1111][1111];int l[1111];
int id[1111],id2[1111];
int dp[1111][1111];
int ct[11],pt[11];
int cst[11];

int tmp1[11],tmp2[11];

int get_dig(int i,int j){
	if(j >= l[i])return 0;
	return a[i][j] - '0';
}

int main(){
	scanf("%s%d",s,&n);
	ls = strlen(s);
	reverse(s,s+ls);
	L = ls;
	for(int i=0; i<n; i++){
		scanf("%s",a[i]);
		l[i] = strlen(a[i]);
		reverse(a[i],a[i]+l[i]);
		L = max(L,l[i]);
		id[i] = i;
	}
	for(int i=0; i<10; i++)
		scanf("%d",&cst[i]);
	L += 2;
	memset(dp,-1,sizeof(dp));
	dp[0][0] = 0;
	int res = 0;
	for(int j=0;;j++){

		memset(ct,0,sizeof(ct));
		int bad0 = 0;
		for(int i=0; i<n; i++){
			ct[get_dig(id[i],j)]++;
			if(j >= max(l[id[i]],ls))
				bad0 ++;
		}

		memset(tmp1,0,sizeof(tmp1));
		memcpy(tmp2,ct,sizeof(tmp2));
		for(int i=0; ; i++){
			if(dp[j][i] != -1){

			if(j == L){
				res = max(res, dp[j][i]);
				continue;
			}

			int from, to;
			if(j >= ls)from = to = 0;else
			if(s[j] == '?'){
				if(j == ls-1)from = 1;else from = 0;
				to = 9;
			}else
				from = to = s[j]-'0';

			for(int d = from; d <= to; d++){
				int pas = 0, tot = 0;
				for(int k = 0; k < 10; k++){
					if(k + 1 + d < 10)
						tot += tmp1[k] * cst[k + 1 + d];
					else{
						tot += tmp1[k] * cst[k + 1 + d - 10];
						pas += tmp1[k];
					}
				}
				for(int k=0; k<10; k++){
					if(k + d < 10){
						tot += (tmp2[k] - (k+d==0?bad0:0)) * cst[k+d];
					}else{
						tot += tmp2[k] * cst[k + d - 10];
						pas += tmp2[k];
					}
				}
				dp[j+1][pas] = max(dp[j+1][pas],dp[j][i] + tot);
			}

			}

			if(i==n)break;
			
			int x = get_dig(id[i],j);
			tmp1[x] ++;
			tmp2[x] --;
			if(j >= max(l[id[i]],ls))bad0--;
		}

		if(j == L)break;
		pt[9] = 0;
		for(int i=8; i>=0; i--)
			pt[i] = pt[i+1] + ct[i+1];
		for(int i=0; i<n; i++){
			id2[pt[get_dig(id[i],j)]++] = id[i];
		}
		memcpy(id,id2,sizeof(int)*n);
	}
	printf("%d\n",res);
	return 0;
}