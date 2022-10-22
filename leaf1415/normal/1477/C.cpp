#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

struct vec2d{
	ll x, y, id;
	vec2d(){}
	vec2d(ll x, ll y){
		this->x = x, this->y = y;
	}
	vec2d(ll x, ll y, ll id){
		this->x = x, this->y = y, this->id = id;
	}
	ll add(ll a, ll b){
		return a+b;
	}
	vec2d operator+(vec2d ope){
		return vec2d(add(x, ope.x), add(y, ope.y));
	}
	vec2d operator-(vec2d ope){
		return vec2d(add(x, -ope.x), add(y, -ope.y));
	}
	vec2d operator*(ll t){
		return vec2d(x*t, y*t);
	}
	vec2d operator/(ll t){
		return vec2d(x/t, y/t);
	}
	ll dot(vec2d ope){
		return add(x*ope.x, y*ope.y);
	}
	ll cross(vec2d ope){
		return add(x*ope.y, -y*ope.x);
	}
};

bool compare(vec2d u, vec2d v)
{
	if(u.x < v.x) return true;
	if(u.x > v.x) return false;
	return u.y < v.y;
}

//NOTE: dest contains the start point twice.
void ConvexHull(vector<vec2d> &src, vector<vec2d> &dest)
{
	sort(src.begin(), src.end(), compare);
	dest.clear();
	dest.resize(2*src.size());
	
	int k = -1;
	for(int i = 0; i < src.size(); i++){
		//if(used[src[i].id]) continue;
		while(k >= 1 && (src[i]-dest[k]).cross(dest[k]-dest[k-1]) >= 0 ) k--;
		dest[k+1] = src[i] ;
		k++;
	}
	for(int i = (int)src.size()-2, t = k; i >= 0; i--){
		//if(used[src[i].id]) continue;
		while(k > t && (src[i]-dest[k]).cross(dest[k]-dest[k-1]) >= 0 ) k--;
		dest[k+1] = src[i];
		k++;
	}
	dest.resize(k+1);
}

ll n;
vec2d p[5005];
bool used[5005];
vector<vec2d> pvec, cvec;
vector<ll> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> p[i].x >> p[i].y, p[i].id = i, pvec.push_back(p[i]);
	//sort(all(pvec), compare);
	
	ll pos;
	rep(i, 1, n-1){
		pvec.clear();
		rep(j, 1, n) if(!used[j]) pvec.push_back(p[j]);
		ConvexHull(pvec, cvec);
		cvec.pop_back();
		
		if(i == 1){
			pos = cvec.front().id;
			ans.push_back(pos);
		}
		used[pos] = true;
		
		ll m = cvec.size(); bool flag = false;
		rep(j, 0, m-1){
			if(cvec[j].id == pos) continue;
			vec2d v = cvec[j] - p[pos];
			vec2d a = cvec[(j+1)%m] - cvec[j], b = cvec[(j+m-1)%m] - cvec[j];
			if(v.dot(a) < 0 && v.dot(b) < 0){
				pos = cvec[j].id;
				flag = true;
				break;
			}
		}
		assert(flag);
		ans.push_back(pos);
	}
	for(auto x : ans) cout << x << " "; cout << endl;
	
	return 0;
}