#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int n;
double T;
double a[N],t[N];
vector<pair<double,double> > angel,devil;

double calc(vector<pair<double,double> > a) {
	double ans = 0;
	for (int i = 0;i < a.size();++i) {
		ans += a[i].first * a[i].second;
	}
	return ans;
}

double calc(vector<pair<double,double> > a,double sum) {
	double ans = 0;
	for(int i = 0;i < a.size();++i) {
		if(a[i].first * a[i].second <= sum) ans += a[i].second, sum -= a[i].first * a[i].second;
		else {
			ans += sum /a[i].first;
			break;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cin >> n >> T;
	double ans = 0;
	for(int i = 0;i < n;++i) cin >> a[i];
	for(int i = 0;i < n;++i) {
		cin >> t[i];
		if(t[i] > T) angel.push_back(make_pair(t[i] - T,a[i]));
		else if(t[i] == T) ans += a[i];
		else devil.push_back(make_pair(T - t[i],a[i]));
	}
	sort(angel.begin(),angel.end());
	sort(devil.begin(),devil.end());
	double sum = min(calc(angel),calc(devil));
	ans += calc(angel,sum) + calc(devil,sum);
	cout << fixed << setprecision(11) << ans << endl;
}