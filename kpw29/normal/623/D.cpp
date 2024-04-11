    #include <vector>
    #include <map>
    #include <set>
    #include <stack>
    #include <bitset>
    #include <algorithm>
    #include <utility>
    #include <sstream>
    #include <iostream>
    #include <iomanip>
    #include <cstdio>
    #include <cmath>
    #include <cstdlib>
    #include <cstring>
    using namespace std;
     
    typedef long double db;
    const db eps = 1e-13;
    int n;
    db p[205], mi[205], now[205];
    int main() {
    	scanf("%d", &n);
     
    	int lim = 500000;
    	for (int i = 1; i <= n; i ++) {
    		int tmp;
    		scanf("%d", &tmp);
    		p[i] = (db)1 - tmp / (db)100;
    		mi[i] = (db)1;
    	}
    	db ans = (db)0;
    	for (int t = 1; t <= lim; t ++) {
    		db cur = (db)1, mul = (db)1;
    		for (int i = 1;i  <= n; i ++)
    			mul = mul * (1 - mi[i]);
    		ans += cur - mul;
     
    		//next mi[]
    		int cho = 0;
    		for (int i = 1; i <= n; i ++) {
    			if (fabs(mi[i] - (db)1) <= eps) {
    				cho = i;
    				break;
    			}
    			now[i] = ((db)1 - mi[i] * p[i]) / ((db)1 - mi[i]);
    			if (cho == 0 || now[i] > now[cho] + eps) cho = i;
    		}
    		mi[cho] = mi[cho] * p[cho];
    	}
    	printf("%.12lf\n", (double)ans);
    	return 0;
    }