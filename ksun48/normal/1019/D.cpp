#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const double PI = atan(1.0) * 4.0;
pair<LL,LL> reference_angle;

vector<pair<LL,LL> > p;

double approx_angle[2100][2100];
pair<LL,LL> diff[2100][2100];

double ang(pair<LL,LL> v1){
	double p1 = atan2(v1.second, v1.first) - atan2(reference_angle.second, reference_angle.first);
	while(p1 > PI * 2.0) p1 -= PI * 2.0;
	while(p1 < 0) p1 += PI * 2.0;
	return p1;
}

inline bool compare(const pair<int, int> a, const pair<int,int> b){
	return approx_angle[a.first][a.second] < approx_angle[b.first][b.second];
}
inline bool compare_init(int a, int b){
	LL area1 = p[a].first * reference_angle.second - p[a].second * reference_angle.first;
	LL area2 = p[b].first * reference_angle.second - p[b].second * reference_angle.first;
	return (area1 < area2);
}

LL area(pair<LL,LL> p1, pair<LL,LL> p2, pair<LL,LL> pi){
	return pi.first * p1.second + p1.first * p2.second + p2.first * pi.second
		 - p1.first * pi.second - p2.first * p1.second - pi.first * p2.second;
}

int main(){
	mt19937 mt(48);
	reference_angle = {mt(), mt()};
	int n;
	LL S;
	cin >> n >> S;
    vector<pair<int,int> > f;
	p.resize(n);
	for(int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
	for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
    		if(p[i] == p[j]) continue;
    		f.push_back({i,j});
    		diff[i][j] = {p[j].first - p[i].first, p[j].second - p[i].second};
    		approx_angle[i][j] = ang(diff[i][j]);
        }
	}
	sort(f.begin(), f.end(), compare);
	reverse(f.begin(), f.end());

	vector<int> idx;
	for(int i = 0; i < n; i++){
		idx.push_back(i);
	}
	sort(idx.begin(), idx.end(), compare_init);
	reverse(idx.begin(), idx.end());

	vector<int> loc(n);
	for(int i = 0; i < n; i++){
		loc[idx[i]] = i;
	}

	for(pair<int,int> x : f){
		pair<LL,LL> p1 = p[x.first];
		pair<LL,LL> p2 = p[x.second];
		LL s = -1;
		LL e = n;
		while(s + 1 < e){
			LL m = (s + e) / 2;
			if(area(p1, p2, p[idx[m]]) < 2 * S){
				s = m;
			} else {
				e = m;
			}
		}
		if(e < n && area(p1, p2, p[idx[e]]) == 2*S){
			cout << "Yes" << endl;
			cout << p1.first << " " << p1.second << endl;
			cout << p2.first << " " << p2.second << endl;
			cout << p[idx[e]].first << " " << p[idx[e]].second << endl;
			return 0;
		}
		int swapped = 0;
		int& a = loc[x.first];
		int& b = loc[x.second];
		swap(a, b);
		swap(idx[a], idx[b]);
	}
	cout << "No" << endl;
}