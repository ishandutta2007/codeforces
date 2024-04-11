#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
void read(pp& x){ scanf("%d%d",&x.first, &x.second); }
void read(pll& x){ scanf("%lld%lld",&x.first, &x.second); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

int x, c;

int last_query = 1;

int ignore_query(){
	int cnt = 0;
	char command[10];
	scanf("%s", command);
	if(command[0] == 's'){
		exit(0);
	}

	sscanf(command, "%d", &cnt);
	last_query = cnt;

	rep(_, cnt) scanf("%*s");
	return cnt;
}

int main()
{
	for(;;){
		++x;
		printf("next 1 2\n"); fflush(stdout);
		ignore_query();
		printf("next 2\n"); fflush(stdout);
		int cnt = ignore_query();
		if(cnt == 2) break;
	}

	for(;;){
		++c;
		printf("next 1\n"); fflush(stdout);
		int cnt = ignore_query();
		if(cnt == 2) break;
	}

	int ce = x/c;
	int tmn = max(0, (ce-1)*c+1);
	int tmx = c * ce;

	rep(i, tmn-1){
		printf("next 0 3 4 5 6 7 8 9\n"); fflush(stdout);
		ignore_query();
	}

	int t;
	for(t=tmn; t<=tmx; ++t){
		printf("next 0 3 4 5 6 7 8 9\n"); fflush(stdout); ignore_query();

		while(x%c != t%c){
			++x;
			printf("next 1 2\n"); fflush(stdout); ignore_query();
		}

		if(last_query == 1){
			puts("done");
		}
	}

	return 0;
}