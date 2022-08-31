    #include <bits/stdc++.h>
    using namespace std;
    typedef long long LL;
     
    const int MOD = 1e9 + 7; 
     
    typedef long long T;
    typedef vector<T> VT;
    typedef vector<VT> VVT;
     
     
    LL powmod(int a, int e){
    	if (e == 0) return 1LL;
    	LL v = powmod(a, e/2);
    	v *= v;
    	v %= MOD;
    	if (e%2 == 1){
    		v *= a;
    		v %= MOD;
    	}
    	return v; 
    }
     
    int rref(VVT &a) {
      int n = a.size();
      int m = a[0].size();
      int r = 0;
      for (int c = 0; c < m && r < n; c++) {
        int j = r;
        for (int i = r + 1; i < n; i++)
          if (abs(a[i][c]) > abs(a[j][c])) j = i;
        if (abs(a[j][c]) == 0) continue;
        swap(a[j], a[r]);
     
        T s = powmod(a[r][c], MOD - 2);
        for (int j = 0; j < m; j++){ 
              a[r][j] *= s; a[r][j] %= MOD;
        }
        for (int i = 0; i < n; i++) if (i != r) {
          T t = a[i][c];
          for (int j = 0; j < m; j++){ 
              a[i][j] -= t * a[r][j];
              a[i][j] %= MOD;
              a[i][j] += MOD;
              a[i][j] %= MOD;
          }
        }
        r++;
      }
      return r;
    }
     
     
    int main(){
    	int m;
    	cin >> m;
    	int d;
    	cin >> d;
    	vector<LL> ans;
    	map<vector<LL>,int> g;
    	int cur = 0;
    	for(int i = 0; i < m; i++){
    		int k;
    		cin >> k;
    		vector<vector<LL> > r;
    		for(int i = 0; i < k; i++){
    			vector<LL> a(d);
    			for(int j = 0; j < d; j++){
    				cin >> a[j];
    			}
    			r.push_back(a);
    		}
    		r.resize(rref(r));
    		LL num = 0;
    		vector<LL> q;
    		for(int i = 0; i < r.size(); i++){
    			for(int j = 0; j < d; j++){
    				q.push_back(r[i][j]);
    			}
    		}
    		if(g.find(q) == g.end()){
    			cur++;
    			g[q] = cur;
    			cout << cur << " ";
    		} else {
    			cout << g[q] << " ";
    		}
    	}
    	cout << endl;
    }