#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A)
#ifdef LOCAL
#define makel(A) scanf("%lld",&A)
#define pll(A) printf("%lld ",A)
#else
#define makel(A) scanf("%I64d",&A)
#define pll(A) printf("%I64d ",A)
#endif
template<typename C> void ma(C& a,C b){if(a<b)a=b;}
template<typename C> void mi(C& a,C b){if(a>b)a=b;}
#define MAX 5011
char z[MAX];
int n;
int dp[MAX],wys[MAX];
const int P = 1e9 +7;
int licz(int dl,int pom){
	int res = 1;
	R(i,dl-1){
		res *= 2;
		res += z[n-dl+i+1] - '0';
		if(res >= P)res -= P;
	}
	res += pom;
	return res % P;
}
vector<vector<int> > s,s2;
main(){
	scanf("%s",z);
	n=0;while(z[n])n++;
	s.PB(vector<int>());
	R(i,n)if(z[i]=='1')s[0].PB(i);
	R(i,n+1)wys[i] = 1e9;
	wys[0] = 1;
	dp[0] = 1;
	int naj = -1;
	R(i,n){
		R(j,s.size()){
			vector<int> gd[2];
			R(k,s[j].size()){
				int ak = s[j][k];
				dp[ak+i+1] += dp[ak];
				if(wys[ak] != 1e9){
					mi(wys[ak+i+1],wys[ak]+1);
					if(ak+i+1 == n){
						if(naj == -1)
							naj = licz(i+1,wys[n]-1);
						if(i <=  20){
							mi(naj,licz(i+1,wys[n]-1));
						}
					}
				}
				if(dp[ak+i+1] >= P)
					dp[ak+i+1] -= P;
				if(ak+i+1 != n)gd[z[ak+i+1]-'0'].PB(ak);
			}
			R(i,2)if(gd[i].size())s2.PB(gd[i]);
		}
		swap(s,s2);
		s2.clear();
	}
	printf("%d\n%d\n",dp[n],naj);
}