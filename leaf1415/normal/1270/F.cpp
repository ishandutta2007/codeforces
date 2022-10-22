#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint n;
string s;
llint sum[200005];
llint B = 450;

llint sum2[200005];
llint calc(llint x)
{
	sum2[0] = 0;
	for(int i = 1; i <= n; i++){
		sum2[i] = sum2[i-1];
		if(s[i] == '1') sum2[i] += x;
		else sum2[i] -= 1;
	}
	sort(sum2, sum2+n+1);
	
	llint ret = 0, cnt = 0;
	for(int i = 0; i <= n; i++){
		if(sum2[i-1] != sum2[i]){
			ret += (cnt-1)*cnt/2;
			cnt = 1;
		}
		else cnt++;
	}
	ret += (cnt-1)*cnt/2;
	return ret;
}

llint calc2(vector<llint> &vec, llint d)
{
	llint m = vec.size();
	llint l = 0, r = 0, ret = 0;
	for(int i = 0; i < m; i++){
		while(l < m && vec[l] < vec[i]+d) l++;
		while(r < m && vec[r] <= vec[i]+d) r++;
		llint ll = max(l, i+B+1);
		ret += max(0LL, r-ll);
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	n = s.size();
	s = "#" + s;
	
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1] + (s[i]-'0');
	}
	
	llint ans = 0, cnt = 0;
	for(int i = 1; i <= n; i++){
		if(s[i] == '1') cnt++;
		else{
			ans += cnt*(cnt+1)/2;
			cnt = 0;
		}
	}
	ans += cnt*(cnt+1)/2;
	for(int i = 1; i < B; i++) ans += calc(i);
	
	for(int i = 1; i <= n/(B+1); i++){
		for(int j = 0; j < i; j++){
			vector<llint> vec;
			for(int k = j; k <= n; k += i) vec.push_back(sum[k]);
			ans += calc2(vec, i);
		}
	}
	cout << ans << endl;
	
	return 0;
}