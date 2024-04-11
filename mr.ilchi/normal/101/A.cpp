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
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int k;
int dp [50];
pii cnt[50];
string s;

int main(){
	
	cin >> s;
	cin >> k;

	for (int i=0; i<26; i++)
		cnt[i] = pii(0,0);
	
	for (int i=0; i<(int)s.size(); i++)
		cnt[s[i]-'a'].first ++;

	for (int i=0; i<26; i++)
		cnt[i].second = i;

	sort (cnt , cnt+26);

	for (int i=0; i<26; i++){
		int tedad = min (k,cnt[i].first);
		k-=tedad;
		cnt[i].first-=tedad;
	}

	for (int i=0; i<26; i++)
		dp[cnt[i].second] = cnt[i].first;

	int res=0;
	for (int i=0; i<26; i++) if (dp[i]>0)
		res++;

	cout << res << endl;

	for (int i=0; i<(int)s.size(); i++) if (dp[s[i]-'a']){
		cout << s[i];
		dp[s[i]-'a']--;
	}
	cout << endl;

	return 0;
}