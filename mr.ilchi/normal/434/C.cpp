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
 */

#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <cstdio> 
#include <cstring> 
#include <cstdlib> 
#include <cmath> 
#include <ctime> 
#include <algorithm> 
#include <vector> 
#include <queue> 
#include <deque> 
#include <stack> 
#include <set> 
#include <map> 
#include <complex> 
#include <bitset> 
#include <iomanip> 
#include <utility> 

using namespace std;

const int mod = 1000000007;
const int base= 701;

int n,m,k,tot,nl,nr;
int score[205],l[205],r[205],val[205];
int next[205][25];
int dp[205][505][205][2];
vector <int> vec[205],Q[205];
map <long long , int> mp;

long long hash (vector <int> Q){
	long long ret = Q.size();
	for (int i=0; i<(int)Q.size(); i++)
		ret = ret * base + Q[i];
	return ret;
}

int solve (int len, int* dig){
	reverse(dig, dig+len);
	memset(dp, 0, sizeof dp);
	for (int pos=len; pos>=0; pos--)
		for (int sc=0; sc<=k; sc++)
			for (int state=0; state<tot; state++)
				for (int t=0; t<2; t++){
					int &ret = dp[pos][sc][state][t];
					if (pos == len)
						ret = 1;
					else{
						for (int c=0; c<m; c++) if ((c<=dig[pos]) || t){
							int nex = next[state][c];
							if (sc + score[nex] <= k){
								ret+= dp[pos+1][sc + score[nex]][nex][t || (c < dig[pos])];
								if (ret>=mod)
									ret-= mod;
							}
						}
					}
				}
	int ret = 0;
	for (int pos=0; pos<len; pos++){
		for (int c = 1; c < m; c++) if ((pos != 0) || (dig[pos] >= c)){
			int N = next[0][c];
			int S = score[N];
			if (S>k) continue;
			ret = (ret + dp[pos+1][S][N][(pos != 0) || (dig[pos] > c)]) % mod;
		}
	}
	reverse(dig, dig+len);
	return ret;
}

int main(){
	cin >> n >> m >> k;
	cin >> nl; for (int i=nl-1; i>=0; i--) cin >> l[i]; 
	cin >> nr; for (int i=nr-1; i>=0; i--) cin >> r[i];
	for (int i=0; i<nl; i++) if (l[i]>0){
		l[i]--;
		for (int j=i-1; j>=0; j--)
			l[j] = m-1;
		while (nl>1 && l[nl-1]==0) 
			nl--;
		break;
	}	
	vec[0] = vector<int>();
	mp[hash(vec[0])] = tot++;
	for (int i=0; i<n; i++){
		int len; cin >> len; 
		for (int j=0; j<len; j++){
			int x; cin >> x;
			Q[i].push_back(x);
			if (mp.find(hash(Q[i])) == mp.end()){
				mp[hash(Q[i])] = tot++;
				vec[tot-1] = Q[i];
			}
		}
		cin >> val[i];
	}
	for (int it = 0; it < tot; it++){
		for (int j=0; j<n; j++) if (Q[j].size() <= (vec[it].size())){
			bool f = true;
			for (int k=0; k<(int)Q[j].size(); k++) if (Q[j][k] != (vec[it][k + (vec[it].size() - Q[j].size())])){
				f = false;
				break;
			}
			if (f)
				score[it]+= val[j];
		}
		for (int i=0; i<m; i++){
			vector <int> cur = vec[it];
			cur.push_back(i);
			while (mp.find(hash(cur)) == mp.end())
				cur.erase(cur.begin());
			next[it][i] = mp[hash(cur)];
		}
	}
	cout << (solve(nr,r) - solve(nl,l) + mod) % mod << endl;
	return 0;
}