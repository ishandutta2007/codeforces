#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <math.h>
#include <unordered_map>
#include <array>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

bool solve() {
	
	srand(time(NULL));
	
	int n, k;

	scanf("%d %d", &n, &k);

	char s[20];

	int ok = 1;

	vec< int > a(n + 1, 11111);

	int cnt = 0;

	for(int i = 0;i <= n;i++) {
		scanf("%s", &s);
		if(s[0] == '?') ok = 0, cnt++;
		else {
			int sz = strlen(s);
			a[i] = 0; 
			for(int j = 0;j < sz;j++) {
				if(s[j] == '-') continue;
				a[i] = a[i] * 10 + s[j] - '0';
			}
			if(s[0] == '-') a[i] = -a[i];
		}
	}

	cnt = n + 1 - cnt;

    if(k == 0) {
        if(a[0] == 0) printf("Yes\n");
        else if(a[0] == 11111) {
            if(cnt % 2) printf("Yes\n");
            else printf("No\n");
        }else {
            printf("No\n");
        }
        return true;
	}

	if(ok) {
	    
	    ll val = 0;
	    
	    const ll maxval = 1ll * 1000 * 1000 * 1000 * 1000;
		
		for(int i = n;i >= 0;i--) {
		    val = val * k + a[i];
		    if(val > maxval || val < -maxval) {
		        printf("No\n");
		        return true;
		    }
		}
		
		if(val == 0) 
		    printf("Yes\n");
	    else
	        printf("No\n");
		
	}else {
	   
		if(n % 2) printf("Yes\n");
		else printf("No\n");
	}

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}