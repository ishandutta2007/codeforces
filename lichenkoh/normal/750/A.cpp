/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class TaskA {
public:
	void solve(std::istream& in, std::ostream& out) {
        ll n,k; in>>n>>k;
        ll have=240-k;
        ll ans=0;
        for (ll i=1;i<=n;i++) {
            have-=5*i;
            if (have>=0) ans=i;
            else break;
        }
        out<<ans<<endl;
	}
};


int main() {
	TaskA solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}