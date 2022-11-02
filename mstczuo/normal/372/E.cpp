# include <iostream>
# include <cstdio>
# include <map>
# include <vector>
# include <algorithm>
using namespace std;
const int MAXN = 1005;
const int Mod = 1000000007;

class num{
	private:
	long long x, y;
	public:
	long long gcd(long long a,long long b){
		for(long long t;b;t=a,a=b,b=t%a);
		return a;
	}
	num (long long _x=0, long long _y=0) {
		x = _x, y = _y;
		long long t = gcd(x, y);
		if(t) x /= t, y /= t;
		if(y<0) x = -x, y = -y;
	}
	void read() {
		cin >> x >> y;
		long long t = gcd(x, y);
		if(t) x /= t, y /= t;
		if(y<0) x = -x, y = -y;
	}
	void write() const {
		cout << x << '/' << y << endl;
	}
	bool friend::operator <(const num&a,const num&b);
	bool friend::operator ==(const num&a,const num&b); 
	num friend::operator +(const num&a,const num&b); 
	num friend::operator -(const num&a,const num&b); 
	num friend::operator *(const num&a,const num&b); 
	num friend::operator /(const num&a,const num&b); 
};

bool operator <(const num&a,const num&b) {
	if (a.y * b.y < 0) return
		(a.x * b.y > b.x * a.y);
	return (a.x * b.y < b.x * a.y);
}

bool operator ==(const num&a,const num&b) {
	return (a.x * b.y == b.x * a.y);
}

num operator +(const num&a,const num&b) {
	return num(a.x * b.y + b.x * a.y, a.y * b.y);
}

num operator -(const num&a,const num&b) {
	return num(a.x * b.y - b.x * a.y, a.y * b.y);
}

num operator *(const num&a,const num&b) {
	return num(a.x * b.x, a.y * b.y);
}

num operator /(const num&a,const num&b) {
	return num(a.x * b.y, a.y * b.x);
}

struct Point{
	num x, y;
	void init() {
		x.read(); y.read(); 
		num t = x*x + y*y;
		x = x/t; y = y/t;
	}
} a[MAXN];

map<pair<num,num>, vector<num> >cs;

int main() {
	ios::sync_with_stdio(false);

	int n; cin >> n;
	for(int i=0; i<n; i++) a[i].init();
	
	for(int i=0; i<n; i++)
		for(int j=0; j<i; j++) 
			cs[make_pair(a[i].x + a[j].x, a[i].y + a[j].y)]
			.push_back((a[i].y - a[j].y)/(a[i].x - a[j].x));

	long long ans = 0;
	for(__typeof(cs.begin())p=cs.begin(); p!=cs.end(); p++) {
		vector<num> &c = p->second;
		sort(c.begin(), c.end());
		int j = 0, m = c.size();
		long long tot = 1;
		for(int i=0; i<m; i=j) {
			while(j<m && c[j] == c[i]) j++;
			ans = (ans + (tot-1) * (j-i))% Mod;
			tot = (tot * (j - i + 1)) % Mod;
		}
	}
	cout << ans << endl;
	return 0;
}