#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int n;
string s;
int used[26][5005][26];
double prob[26][5005];
double p[26];
int cnt[26];

int main(void)
{
	cin >> s;
	n = s.size();
	s = s + s;
	
	for(int i = 0; i < n; i++){
		for(int j = 1; j < n; j++){
			used[s[i]-'a'][j][s[i+j]-'a']++;
		}
	}
	
	for(int i = 0; i < 26; i++){
		for(int j = 1; j < n; j++){
			int sum = 0, cnt = 0;
			for(int k = 0; k < 26; k++){
				sum += used[i][j][k];
				if(used[i][j][k] == 1) cnt++;
			}
			prob[i][j] = (double)cnt / (double)sum;
		}
	}
	
	double val;
	for(int i = 0; i < 26; i++){
		val = 0;
		for(int j = 1; j < n; j++){
			val = max(val, prob[i][j]);
		}
		p[i] = val;
	}
	
	for(int i = 0; i < n; i++) cnt[s[i]-'a']++;
	
	double ans = 0;
	for(int i = 0; i < 26; i++){
		ans += (double)cnt[i] / (double)n * p[i];
	}
	printf("%.10f\n", ans);
	return 0;
}