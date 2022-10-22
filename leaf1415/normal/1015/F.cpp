#include <iostream>
#include <string>
#define llint long long
#define mod 1000000007

using namespace std;

int n;
string s;
int Next[205][2];
const char c[] = {'(', ')'};
llint dp[205][205][205];

llint fact[2005], fact_inv[2005];

llint pow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (pow(a, n-1)%mod)) % mod;
	}
	else{
		return pow((a*a)%mod, n/2) % mod;
	}
}

void make_fact()
{
	llint val = 1;
	fact[0] = 1;
	for(int i = 1; i < 2005; i++){
		val *= i;
		val %= mod;
		fact[i] = val;
	}
	for(int i = 0; i < 2005; i++){
		fact_inv[i] = pow(fact[i], mod-2);
	}
}

int main(void)
{
	cin >> n;
	cin >> s;
	make_fact();
	
	for(int i = 0; i < s.size(); i++){
		for(int j = 0; j < 2; j++){
			string t = s.substr(0, i) + c[j];
			while(s.substr(0, t.length()) != t){
				t = t.substr(1);
			}
			Next[i][j] = t.length();
		}
	}
	
	dp[0][0][0] = 1;
	for(int i = 0; i < 2*n; i++){
		for(int j = 0; j <= 2*n; j++){
			for(int k = 0; k < s.size(); k++){
				if(k != s.size()-1 || s[s.size()-1] != c[0]){
					dp[i+1][j+1][Next[k][0]] += dp[i][j][k];
					dp[i+1][j+1][Next[k][0]] %= mod;
				}
				if(k != s.size()-1 || s[s.size()-1] != c[1]){
					if(j > 0){
						dp[i+1][j-1][Next[k][1]] += dp[i][j][k];
						dp[i+1][j-1][Next[k][1]] %= mod;
					}
				}
			}
		}
	}
	
	llint ans = 0;
	for(int i = 0; i < s.size(); i++){
		ans += dp[2*n][0][i];
		ans %= mod;
	}
	ans = fact[2*n] * fact_inv[n+1] % mod * fact_inv[n] % mod + (mod - ans);
	cout << ans % mod << endl;
	return 0;
}