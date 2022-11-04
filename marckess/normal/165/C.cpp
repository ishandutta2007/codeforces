#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef vector<int> vi;

int k;
string s;

int main (){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> k >> s;
	if(!k){
		long long sum=0;
		int idx=0;
		bool ok=false;
		for(int i=0;i<s.size();i++){
			if(s[i]=='1'){
				if(ok)sum+=((long long)((long long)(i-idx)*(long long)((i-idx)+1LL))/2LL);
				ok=false;
			}
			else if(s[i]=='0'){
				if(!ok){
					idx=i;
					ok=true;
				}
				if(i==s.size()-1)sum+=((long long)((long long)(s.size()-idx)*(long long)((long long)(s.size()-idx)+1LL))/2LL);
			}
		}
		cout << sum<<"\n";
		return 0;
	}
	vi v(s.size()+2, 0);
	
	for (int i = 1; i <= s.size(); i++) 
		v[i] += v[i-1] + s[i-1] - '0';
		
	long long res = 0;
	for (int i = 1; i <= s.size(); i++) {
		int val = v[i] - k;
		res += upper_bound (v.begin(), v.begin() + i + 1, val )
		       - lower_bound (v.begin(), v.begin() + i + 1, val );
	}
	
	cout << res << endl;
	
	return 0;
}