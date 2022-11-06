#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll unsigned long long
string give,ask;

ll getask(ll start, ll end) {
	if (start >= end) {
		return 0;
	}
	ll asklen = ask.length();
	ll givelen = give.length();
	ll ans = 0;
	ll x = 0;
	ll pos = start;
	ll counter = 0;
	ll numask = 0;
	while(1) {
		if (pos >= end) {
			break;
		}
		ll y = pos % givelen;
		if (ask[x] == give[y]) {
			x++;
			counter = 0;
		}
		pos++;
		counter++;
		if (x >= asklen) {
			x = x % asklen;
			numask++;
		}
	}
	return numask;
}

int main() {
	ll b,d;

	cin >> b;
	cin >> d;
	cin >> give;
	cin >> ask;
	ll asklen = ask.length();
	ll givelen = give.length();
	ll x = 0;
	ll y = 0;
	bool first = true;	
	ll numask = 0;
	ll numgive = 0;
	ll counter = 0;
	vector<ll> inity;
	vector<ll> initynumask;
	vector<ll> vpos;
	ll startnumask = 0;
	ll pos = 0;
	ll startinity = 0;
	ll startpos = 0;
	while(1) {
		if (counter > 2*givelen) {
			cout << 0 << endl;
			return 0;
		}
		if (ask[x] == give[y]) {
			if (x==0) {
				vector<ll>::iterator it = find(inity.begin(),inity.end(),y);
				if (it != inity.end()) {
					startinity = *it;
					startnumask = *(initynumask.begin() + (it-inity.begin()));
					startpos = *(vpos.begin() + (it-inity.begin()));
					break;
				}
				inity.push_back(y);
				initynumask.push_back(numask);
				vpos.push_back(pos);
			}
			x++;
			counter = 0;
		}
		y++;
		pos++;
		counter++;
		if (x >= asklen) {
			x = x % asklen;
			numask++;
		}
		if (y >= givelen) {
			y = y % givelen;
			numgive++;
		}
	}
	ll cyclelen = pos - startpos;
	ll cycleask = numask - startnumask;
	ll end = b*givelen;
	ll total = 0;
	if (end < startpos) {
		total = getask(0,end);
	}
	else {
		ll m = (end-startpos)/cyclelen;
		total = startnumask + m * cycleask + getask(startpos+m*cyclelen,end);
	}
	//cout << total << endl;
	cout << total/d << endl;

	return 0;
}