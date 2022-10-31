/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const ll base = 811;
const int maxN = 100*1000 + 10; 
const int mod = 1e9 + 7;

int nex[maxN];
ll tav[maxN];
int cnt[maxN];

vector<int> KMP(string S, string K)
{
        vector<int> T((int)K.size() + 1, -1);
	vector<int> matches;
 
        if((int)K.size() == 0)
        {
            matches.push_back(0);
            return matches;
        }
	for(int i = 1; i <= (int)K.size(); i++)
	{
		int pos = T[i - 1];
		while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
		T[i] = pos + 1;
	}
 
	int sp = 0;
	int kp = 0;
	while(sp < (int)S.size())
	{
		while(kp != -1 && (kp == (int)K.size() || K[kp] != S[sp])) kp = T[kp];
		kp++;
		sp++;
		if(kp == (int)K.size()) matches.push_back(sp - (int)K.size());
	}
 
	return matches;
}

int main() { 
	tav[0] = 1;
	for( int i = 1 ; i < maxN ; i++) 
		tav[i] = tav[i-1]*base;

	string s,t;
	cin >> s >> t; 

	fill( nex , nex + sz(s) , sz(s) ) ; 
	auto x = KMP(s,t);
	for( int i = 0 ; i < sz(x) ; i++ ) {
		for( int j = (i == 0 ? 0 : x[i-1] + 1) ; j <= x[i]; j++ )
			nex[j] = x[i] + sz(t) - 1 ; 
	}

	int ret = 0;
	int sum = 0;
	for( int i =0  ; i < sz(s) ; i++ ) { 
		cnt[nex[i]] += (i-1==-1?1:cnt[i-1]);
		if( cnt[nex[i]] >= mod ) cnt[nex[i]] -= mod;
		sum += cnt[i];
		if( sum >= mod ) sum -= mod;
		cnt[i] = sum + (i-1==-1?1:cnt[i-1]);
		if( cnt[i] >= mod ) cnt[i] -= mod;
		ret += sum;
		if( ret >= mod ) ret -= mod;
	}
	cout << ret << endl;
}