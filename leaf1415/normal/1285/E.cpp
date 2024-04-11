#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;

llint T;
llint n;
llint l[200005], r[200005];
llint dif[400015], sum[400015];
llint usum[400015];
vector<llint> comp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> l[i] >> r[i];
			l[i] *= 2;
			r[i] = r[i]*2 + 1;
		}
		
		comp.clear();
		for(int i = 1; i <= n; i++){
			comp.push_back(l[i]);
			comp.push_back(r[i]);
		}
		sort(comp.begin(), comp.end());
		comp.erase(unique(comp.begin(), comp.end()), comp.end());
		for(int i = 1; i <= n; i++){
			l[i] = lower_bound(comp.begin(), comp.end(), l[i]) - comp.begin() + 1;
			r[i] = lower_bound(comp.begin(), comp.end(), r[i]) - comp.begin() + 1;
		}
		
		for(int i = 1; i < 2*n+5; i++) dif[i] = 0;
		for(int i = 1; i <= 2*n+5; i++) sum[i] = 0;
		for(int i = 1; i <= n; i++) dif[l[i]]++, dif[r[i]]--;
		for(int i = 1; i < 2*n+5; i++) sum[i] = sum[i-1] + dif[i];
		
		for(int i = 1; i < 2*n+5; i++){
			usum[i] = usum[i-1];
			if(sum[i] == 1) usum[i]++;
		}
		
		llint num = 0;
		for(int i = 0; i < 2*n+5; i++){
			if(sum[i] == 0 && sum[i+1] > 0) num++;
		}
		
		//for(int i = 1; i <= n; i++)  cout<< l[i] << " " << r[i] << endl;
		//for(int i = 1; i <= 2*n+5; i++)  cout<< usum[i] << " "; cout << endl;
		
		llint ans = -inf;
		for(int i = 1; i <= n; i++){
			llint tmp = usum[r[i]-1] - usum[l[i]-1];
			bool lflag = (sum[l[i]] == 1 && sum[l[i]-1] == 0);
			bool rflag = (sum[r[i]-1] == 1 && sum[r[i]] == 0);
			///cout << tmp << endl;
			if(tmp == r[i]-l[i] && lflag && rflag) tmp = -1;
			else{
				if(lflag) tmp--; if(rflag) tmp--;
			}
			ans = max(ans, tmp);
		}
		cout << num+ans << "\n";
	}
	flush(cout);
	
	return 0;
}