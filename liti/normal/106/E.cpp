//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

const int N = 100 + 100;
struct point { 
    ld x, y, z;
}; 

ld dis2(point a, point b) { 
    ld dx = a.x-b.x;
    ld dy = a.y-b.y;
    ld dz = a.z-b.z; 
    return dx * dx + dy * dy + dz * dz; 
}

point a[N]; 

int main() {
    int n;
    cin >> n ;
    point curr = {0, 0, 0}; 
    for(int i = 0; i < n; i++) { 
        cin >> a[i].x >> a[i].y >> a[i].z; 
        curr.x += a[i].x;
        curr.y += a[i].y;
        curr.z += a[i].z;
    }

    ld z = 0.1;
    for(int t = 2; t < 70000; t++) { 
        point far = a[0]; 
        ld dis = dis2(curr, far); 
        for(int i = 0; i < n; i++) 
            if( dis < dis2(curr, a[i]) ) { 
                far = a[i];
                dis = dis2(curr, far); 
            }
        curr.x += (far.x-curr.x) * z;
        curr.y += (far.y-curr.y) * z;
        curr.z += (far.z-curr.z) * z;
        
        z *= 0.998;
    }

    cout << fixed << setprecision(20) << curr.x << ' ' << curr.y << " " << curr.z << endl;
    return 0;
}