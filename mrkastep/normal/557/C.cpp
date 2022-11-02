#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ll long long int
#define all(v) (v).begin(),(v).end()

const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

typedef pair<double,double> point;

bool great(pair<int,int> a,pair<int,int> b){return a>b;}

void solve(int n){
	vector<pair<int,int>> l(n);
	vector<int> d(222,0);
	For(i,n){
		scanf("%d",&l[i].x);
	}
	For(i,n){
		scanf("%d",&l[i].y);
		d[l[i].y]++;
	}
	sort(all(l),great);
	int sum=0;
	int ans=INF;
	For(i,n){
		int s=0,p=i,c;
		while(p<n&&l[p].x==l[i].x){
			s+=l[p].y;
			d[l[p].y]--;
			p++;
		}
		c=p-i;
		int del=n-p-c+1;
		int tmp=0;
		For(j,222){
			if(del<=0) break;
			if(d[j]>=del){
				tmp+=del*j;
				break;
			}
			del-=d[j];
			tmp+=j*d[j];
		}
		ans=min(ans,sum+tmp);
		sum+=s;
		i=p-1;
	}
	printf("%d",ans);







}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
#endif
	int n,cnt;
	ll a;
	string t;
	char c[5555];
	while(scanf("%d",&n)==1) solve(n);
	return 0;
}