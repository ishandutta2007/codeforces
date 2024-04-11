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
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <complex>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const double eps = 1e-9;

int comp;
int hp[2],dt[2],l[2],r[2];
double p[2];
double no[70],cost[70];
double f [210][210][70];
double dp[210][210][70];
vector <int> C[70];

int main(){

	cin >> hp[0] >> dt[0] >> l[0] >> r[0] >> p[0]; p[0]/=100.0;
	cin >> hp[1] >> dt[1] >> l[1] >> r[1] >> p[1]; p[1]/=100.0; 

	if (p[0]>0.999) { cout << 0.0 << endl; return 0; }
	if (p[1]>0.999) { cout << 1.0 << endl; return 0; }

	vector <int> Q;

	double mulNo = 1.0;

	for (int t=0; t<dt[0]*dt[1]/__gcd(dt[0],dt[1]); t++) if (t%dt[0]==0 || t%dt[1]==0){
		no[(int)Q.size()]=1.0;
		if (t%dt[0]==0) no[(int)Q.size()]*= p[0];
		if (t%dt[1]==0) no[(int)Q.size()]*= p[1];
		Q.push_back(t);
		mulNo*= no[(int)Q.size()-1];
	}

	int n = (int)Q.size();
	
	for (int k=0; k<n; k++) if (no[k]<eps){
		comp++;
		int tmp=(k-1+n)%n;
		while (no[tmp]>eps){
			C[comp].push_back(tmp);
			tmp = (tmp-1+n)%n;
		}
		reverse(C[comp].begin(),C[comp].end());
		C[comp].push_back(k);
	}

	for (int i=0; i<=hp[0]; i++){
		for (int j=0; j<=hp[1]; j++){
			for (int k=0; k<n; k++){
				if (i==0 || j==0){ 
					dp[i][j][k] = (j==0) ? 1.0 : 0.0;
					if (k==0)
						f [i][j][k] = max(0,(r[0]-max(l[0],j)+1)) * (r[1]-l[1]+1);
					else if (Q[k]%dt[0]==0)
						f [i][j][k] = max(0,(r[0]-max(l[0],j)+1));
					else
						f [i][j][k] = (r[1]-l[1]+1.0) * (j==0);
					continue;
				}

				int kk = (k+1)%n;
				if 	(k==0){	

					double prob0 = (1-p[0])/(r[0]-l[0]+1.0)*p[1];
					double prob1 = (1-p[1])/(r[1]-l[1]+1.0)*p[0];
					double prob01= (1-p[0])/(r[0]-l[0]+1.0)*(1-p[1])/(r[1]-l[1]+1.0);

					for (int d=l[0]; d<=r[0]; d++) dp[i][j][k]+= dp[i][max(0,j-d)][kk] * prob0;
					for (int d=l[1]; d<=r[1]; d++) dp[i][j][k]+= dp[max(0,i-d)][j][kk] * prob1;

					f[i][j][k] = f [i][j-1][k] + f[i-1][j][k] - f[i-1][j-1][k];

					f[i][j][k]-= dp[max(0,i-l[1])][max(0,j-1-r[0])][kk];
					f[i][j][k]-= dp[max(0,i-1-r[1])][max(0,j-l[0])][kk];
					f[i][j][k]+= dp[max(0,i-1-r[1])][max(0,j-1-r[0])][kk];
					f[i][j][k]+= dp[max(0,i-l[1])][max(0,j-l[0])][kk];

					dp[i][j][k]+= f[i][j][k] * prob01; 
				}
				else if (Q[k]%dt[0]==0){
					double prob = (1-p[0]) / (r[0]-l[0]+1.0);
					f [i][j][k] = f [i][j-1][k] + dp[i][max(0,j-l[0])][kk] - dp[i][max(0,j-1-r[0])][kk];
					dp[i][j][k] = f [i][j][k] * prob;
				}
				else{
					double prob = (1-p[1]) / (r[1]-l[1]+1.0);
					f [i][j][k] = f [i-1][j][k] + dp [max(0,i-l[1])][j][kk] - dp[max(0,i-1-r[1])][j][kk];
					dp[i][j][k] = f [i][j][k] * prob;
				}
			}

			if (i!=0 && j!=0){

				if (comp==0){
					double calc = 1 / (1 - mulNo) , past = 1.0;
					cost[0] = 0.0;
					for (int k=0; k<n; k++){
						cost[0]+= calc * past * dp[i][j][k];
						past*=no[k];
					}
					for (int k=0; k<n; k++){
						cost[1] = (cost[0] - calc * dp[i][j][k] + mulNo * calc * dp[i][j][k]) / no[k];
						dp[i][j][k] = cost[0];
						cost[0] = cost[1];
					}
				}
				else{
					for (int k=1; k<=comp; k++){
						double past = 0;
						for (int kk=(int)C[k].size()-1; kk>=0; kk--){
							int ind = C[k][kk];
							past = past * no[ind] + dp[i][j][ind];
							dp[i][j][ind] = past;
						}
					}
				}
			}
		}
	}

	cout << fixed << setprecision(9) << dp[hp[0]][hp[1]][0] << endl;

	return 0;
}