#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define trav(x,v) for(auto &x : v)
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define rrep(i,a,b) for(int i = b; i --> a;)
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
int tab[8];

void solveOne() {
    int k;
    cin >> k;
    int sum  =0 ;
    for (int i=0; i<7; ++i) cin >> tab[i], sum += tab[i];
    int tries = (k / sum) - 1;
    int result = 7 * tries;
    k = k - tries * sum;
    int best = 1000;
    for (int i=0; i<7; ++i) {

        for (int len = 0; len < 30; ++len) {
             int score = 0;
             for (int id = 1; id <= len; ++id) {
                score += tab[(i + id - 1) % 7];
             }
             if (score >= k) best = min(best, len);
        }

    }

    cout << result + best << "\n";
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int t;
	cin >> t;

	while (t--) solveOne();
}