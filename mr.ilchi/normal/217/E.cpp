/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int MAXN = 100000+10;
const int MAXL = 3000000+10;

char ans[MAXL],s[MAXL];
int N=1,que,k,begin;
int l[MAXN],r[MAXN],lo[MAXN],hi[MAXN],nex[MAXN],prev[MAXN],poi[MAXL];	
//string s;

void PRINT (){
	int start = begin;
	while (start){
		cout << lo[start] << ' ' << hi[start] << endl;
		start = nex[start];
	}
	cout << endl;
}

int goNext(int &cur, int &past, const int &need) { while (cur!=0 && past+hi[cur]-lo[cur]+1<need) past+=hi[cur]-lo[cur]+1, cur=nex[cur];  return lo[cur]+need-past-1; }

int main(){
//	ios_base::sync_with_stdio(false);
//	cin >> s >> k >> que;
	scanf("%s%d%d", s, &k, &que);
	for (int i=1; i<=que; i++)
		cin >> l[i] >> r[i]; 
	lo [1]=1, hi[1]=k;
	nex[0]=1, prev[0]=1;
	begin=1;
	for (int i=que; i>0; i--){
		int cur=begin, sz=0;
		goNext(cur,sz,r[i]+1);
		if (cur==0)
			continue;
		int rem = r[i]-l[i]+1, len=r[i]-l[i]+1;
		int pos = lo[cur]+r[i]-sz;
		int beg = begin, past=0;
		int g1=cur,p1=pos;
		int g2=cur,p2=pos;
		while (rem && cur){
			g2=cur,p2=pos;
			if (rem == (len+1)/2)
				beg=begin, past=0;
			if (rem <= (len+1)/2)
				poi[pos] = goNext(beg,past,((len+1)/2-rem+1)*2-1+l[i]-1);
			else
				poi[pos] = goNext(beg,past,(len-rem+1)*2 + l[i]-1);	
			if (pos==hi[cur]){
				cur=nex[cur];
				pos=lo[cur];
			}
			else
				pos++;
			rem--;
		}
		int f1 = (lo[g1]==p1) ? (prev[g1]) : (-1);
		int f2 = (hi[g2]==p2) ? (nex [g2]) : (-1);
		if (f1==-1) { N++; f1=N; nex[prev[g1]]=N; prev[N]=prev[g1]; lo[N]=lo[g1], hi[N]=p1-1; if (prev[f1]==0) begin=f1; }
		if (f2==-1) { N++; f2=N; prev[nex[g2]]=N; nex [N]=nex [g2]; lo[N]=p2+1, hi[N]=hi[g2]; }
		nex[f1]=f2; prev[f2]=f1;
	}
	int past=0, start=begin;
	while (start!=0){
		while (lo[start]<=hi[start])
			ans[lo[start]++] = s[past++];
		start = nex[start];
	}
	for (int i=1; i<=k; i++) if (!ans[i]){
		int cur = i;
		while (!ans[cur]) cur = poi[cur];
		ans[i] = ans[cur];
		cur = poi[i];
		while (!ans[cur]) ans[cur]=ans[i], cur=poi[cur]; 
	}
	puts(&ans[1]);
	return 0;
}