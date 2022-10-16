#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int N = 3005;
int n, m, K, t, tot = 0;
int f[N];
string s[N];
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> K;
	t = 4 * n * m - 2 * n - 2 * m;
	if (K > t) { puts("NO"); return 0; }
	int h = (m - 1) * 2 + 1, now = h * (n - 1);
	if (K <= now) {
		int a = K / h;
		for (int i = 1; i <= a; i++) {
			if (m != 1) {
			    f[++tot] = m - 1;
    			s[tot] = "R";
    			f[++tot] = m - 1;
    			s[tot] = "L"; 
			}
			f[++tot] = 1;
			s[tot] = "D";
		}


		a = K % h;
		if (a) {
    		if (a <= m - 1) {
    			f[++tot] = a;
    			s[tot] = "R";
    		} else {
    			a -= m - 1;
    			if (m != 1){
    			    f[++tot] = m - 1;
    			    s[tot] = "R";
    			}
    			f[++tot] = a;
    			s[tot] = "L";
    		}    
		}
		

	} else {
		for (int i = 1; i <= n - 1; i++) {
			if (m != 1) {
			    f[++tot] = m - 1;
    			s[tot] = "R";
    			f[++tot] = m - 1;
    			s[tot] = "L"; 
			}
			
			f[++tot] = 1;
			s[tot] = "D";
		}
		K -= now;
        if (K) {
            if (K <= m - 1) {
    			f[++tot] = K;
    			s[tot] = "R";
    		} else {
    		    if (m != 1) {
        		    f[++tot] = m - 1;
        			s[tot] = "R";    
    		    }
    			
    			K -= m - 1;
    			h = (n - 1) * 2 + 1, now = h * (m - 1);
    			if (K <= now) {
    				int a = K / h;
    				for (int i = 1; i <= a; i++) {
    				    if (n != 1) {
    				       f[++tot] = n - 1;
        					s[tot] = "U";
        					f[++tot] = n - 1;
        					s[tot] = "D"; 
    				    }
    					
    					f[++tot] = 1;
    					s[tot] = "L";
    				}
    				a = K % h;
    				if (a) {
        				if (a <= n - 1) {
        					f[++tot] = a;
        					s[tot] = "U";
        				} else {
        					if (n != 1){
        					    f[++tot] = n - 1;
        					    s[tot] = "U";   
        					}
        					
        					a -= n - 1;
        					f[++tot] = a;
        					s[tot] = "D";
        				}    
    				}
    				
    			} else {
    				for (int i = 1; i <= m - 1; i++) {
    					if (n != 1){
        					f[++tot] = n - 1;
        					s[tot] = "U";
        					f[++tot] = n - 1;
        					s[tot] = "D";
    					}
    					f[++tot] = 1;
    					s[tot] = "L";
    				}
    				K -= now;
    				if (K) {
    
    					f[++tot] = K;
    					s[tot] = "U";
    				}
    			} 
    		}    
        }
		
	}
	cout << "YES" << endl;
	cout << tot << endl;
	for (int i = 1; i <= tot; i++) {
		cout << f[i] << " " << s[i] << endl;
	}
	return 0;
}