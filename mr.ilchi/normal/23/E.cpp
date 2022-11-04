/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int BASE = 10000;
const int maxN = 700+5;
const int maxL = 30;

bool mark[maxN];
int n;
vector <int> adj[maxN];

struct Bint{
	int len;
	int dig[maxL];

	Bint(){
		len=1; memset (dig, 0, sizeof dig);
	}

	inline bool operator < (const Bint &a2) const{
		if (len!=a2.len)
			return len < a2.len;
		for (int i=len-1;i>=0;i --) if (dig[i]!=a2.dig[i])
			return dig[i] < a2.dig[i];
		return false;
	}	

	inline Bint operator * (const Bint &a2) const{
		Bint ret;
		for (int i=0;i<len;i ++)
			for (int j=0;j<a2.len;j++)
				ret.dig[i+j]+= dig[i] * a2.dig[j];

		for (int i=0, leni=maxL-1;i<leni;i ++){
			ret.dig[i+1]+= ret.dig[i]/BASE; ret.dig[i]%=BASE;
		}

		for (int i=maxL-1;i>=0;i --) if (ret.dig[i]){
			ret.len= i+1; return ret;
		}		

		return ret;
	}

	inline Bint operator * (const int &a2) const{
		Bint ret;
		
		for (int i=0;i< len;i ++)
			ret.dig[i]= dig[i] * a2;

		for (int i=0, leni=maxL-1;i<leni;i ++){
			ret.dig[i+1]+= ret.dig[i]/BASE; ret.dig[i]%=BASE;
		}

		for (int i=maxL-1;i>=0;i --) if (ret.dig[i]){
			ret.len= i+1; return ret;
		}

		return ret;
	}

	inline void print()const{
		printf ("%d", dig[len-1]);
		for (int i=len-2;i>=0;i --)
			printf ("%04d", dig[i]);
	}
};	
Bint DP[maxN], leaf[maxN];
Bint dp[maxN][maxN];
/***************************************/
inline void dfs (int v){
	mark[v]= true; dp[v][0].dig[0]= 1; 
	int cnt=0;
	for (int i=0;i< (int)adj[v].size();i ++){
		int tmp= adj[v][i];
		if (!mark[tmp]){
			dfs (tmp); cnt ++;
			for (int j=cnt;j>0;j --)
				dp[v][j]= max (dp[v][j] * DP[tmp], dp[v][j-1] * dp[tmp][0]);

			leaf[v]= leaf[v] * DP[tmp];
			for (int j=0;j<n;j ++){
				if (leaf[v] < dp[v][0] * dp[tmp][j] * (j+2)){
					leaf[v] = dp[v][0] * dp[tmp][j] * (j+2);
				}
			}

			dp[v][0]= dp[v][0] * DP[tmp];
		}
	}

	DP[v]= leaf[v];
	for (int i=0;i<n;i ++){
		DP[v]= max (DP[v], dp[v][i] * (i+1));
	}	
}		
/*************************************/
int main(){
	scanf ("%d", &n);
	for (int i=1;i<n;i ++){
		int x,y; scanf ("%d%d", &x, &y);
		adj[x].push_back (y);
		adj[y].push_back (x);
	}

	dfs (1);
	DP[1].print (); printf ("\n");

	return 0;
}