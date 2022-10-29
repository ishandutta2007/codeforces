#include <bits/stdc++.h>
#define snd second
#define pb push_back
#define fst first
#define mp make_pair
#define fore(i,a,n) for(int i = a, qwer = n;i<qwer;i++)

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 100500;
int mn[200],mx[200],a[200];
int nop;
int main() {
	int tn;
	cin >> tn;
	fore(tc,0,tn) {
		nop=0;
		int n;
		cin >> n;
		int h = 0;
		char c;
		for(int i = 0;i<n-1;i+=2) {
			nop++;
			int u = i+1, v = i+2;
			cout << "? " << u << " " << v << endl;
			fflush(stdout);
			cin >> c;
			if(c == '>') {
				mx[h] = u;
				mn[h] = v;
			} else if(c == '=') {
				mn[h] = u;
				mx[h] = u;
			} else {
				mn[h] = u;
				mx[h] = v;
			}
			h++;
		}
		if(n % 2 == 1) {
		 	mn[h] = mx[h] = n;
		 	h++;
		}
		int hh = h;
		int w;
		while(h > 1) {
			w = 0;
			for(int i = 0;i<h-1;i+=2) {
				nop++;
				int u = i, v = i + 1;
				cout << "? " << mn[u] << " " << mn[v] << endl;
				fflush(stdout);
				cin >> c;
				if(c == '=')
					mn[w] = mn[u];
				else if(c == '<')
					mn[w] = mn[u];
				else
					mn[w] = mn[v];
				w++;
			}
			if(h % 2 == 1)
				mn[w++] = mn[h-1];
			h = w;
		}
		h = hh;
		while(h > 1) {
			w = 0;
			for(int i = 0;i<h-1;i+=2) {
				nop++;
				int u = i, v = i+1;
				cout << "? " << mx[u] << " " << mx[v] << endl;
				fflush(stdout);
				cin >> c;
				if(c == '=')
					mx[w] = mx[u];
				else if(c == '>')
					mx[w] = mx[u];
				else
					mx[w] = mx[v];
				w++;
			}
			if(h % 2 == 1)
				mx[w++] = mx[h-1];
			h = w;
		}
		cout << "! " << mn[0] << " " << mx[0] << endl;
		fflush(stdout);
		//printf("%d %d\n",nop,(3*n+1)/2-2);
	}
	return 0;
}