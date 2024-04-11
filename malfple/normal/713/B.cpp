#include <iostream>
#include <cstdio>

#include <cstring>
#include <string>

#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>

#include <queue>
#include <utility>
#include <set>
#include <stack>
#include <vector>
#include <map>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define repp(i,a,b,d) for(int i=a;i<=b;i+=d)
#define rep(i,a,b) repp(i,a,b,1)
#define revv(i,a,b,d) for(int i=a;i>=b;i-=d)
#define rev(i,a,b) revv(i,a,b,1)

#define mp make_pair

#define pb push_back
#define ff first
#define ss second

const int OO = 1e9;
const ll INF = 1e18;

const int irand(int lo,int hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

const ll lrand(ll lo,ll hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

//end of macro

int n;

inline void query(int a,int b,int c,int d){
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();

    cin>>n;

    int x1=1,x2=1,x3=n,x4=n;
    int lo,mid,hi,a;

    lo = 1, hi = n;
    while(lo <= hi){
        mid = (lo+hi)/2;
        query(1,1,n,mid);
        cin>>a;

        if(a == 0){
            lo = mid+1;
        }else{
            hi = mid-1;
            x3 = min(x3, mid);
        }
    }

    lo = 1, hi = n;
    while(lo <= hi){
        mid = (lo+hi)/2;
        query(1,1,n,mid);
        cin>>a;

        if(a <= 1){
            lo = mid+1;
        }else{
            hi = mid-1;
            x4 = min(x4, mid);
        }
    }

    lo = 1, hi = n;
    while(lo <= hi){
        mid = (lo+hi)/2;
        query(1,mid,n,n);
        cin>>a;

        if(a == 0){
            hi = mid-1;
        }else{
            lo = mid+1;
            x2 = max(x2, mid);
        }
    }

    lo = 1, hi = n;
    while(lo <= hi){
        mid = (lo+hi)/2;
        query(1,mid,n,n);
        cin>>a;

        if(a <= 1){
            hi = mid-1;
        }else{
            lo = mid+1;
            x1 = max(x1, mid);
        }
    }

    if(x1 == x2 && x3 == x4){
        int y1=1,y2=1;
        int y3=n,y4=n;

        lo = 1, hi = n;
        while(lo <= hi){
            mid = (lo+hi)/2;
            query(mid,x1,n,x4);
            cin>>a;

            if(a == 0){
                hi = mid-1;
            }else{
                lo = mid+1;
                y2 = max(y2, mid);
            }
        }

        lo = 1, hi = n;
        while(lo <= hi){
            mid = (lo+hi)/2;
            query(mid,x1,n,x4);
            cin>>a;

            if(a <= 1){
                hi = mid-1;
            }else{
                lo = mid+1;
                y1 = max(y1, mid);
            }
        }

        lo = 1, hi = n;
        while(lo <= hi){
            mid = (lo+hi)/2;
            query(1,x1,mid,x4);
            cin>>a;

            if(a == 0){
                lo = mid+1;
            }else{
                hi = mid-1;
                y3 = min(y3, mid);
            }
        }

        lo = 1, hi = n;
        while(lo <= hi){
            mid = (lo+hi)/2;
            query(1,x1,mid,x4);
            cin>>a;

            if(a <= 1){
                lo = mid+1;
            }else{
                hi = mid-1;
                y4 = min(y4, mid);
            }
        }

        cout << "! " << y1 << " " << x1 << " " << y3 << " " << x4 << " " << y2 << " " << x1 << " " << y4 << " " << x4 << endl;

        return 0;
    }

    bool topdown = false;
    if(x2 <= x3){
        query(1,x2,n,x3);
        cin>>a;

        if(a >= 1){
            swap(x2, x4);
            swap(x3, x4);
            topdown = true;
        }else{
            swap(x2, x3);
        }
    }else{
        swap(x2, x3);
    }

    int y1=1,y2=n;
    int y3=1,y4=n;

    lo = 1, hi = n;
    while(lo <= hi){
        mid = (lo+hi)/2;
        query(mid,x3,n,x4);
        cin>>a;

        if(a == 0){
            hi = mid-1;
        }else{
            lo = mid+1;
            y3 = max(y3, mid);
        }
    }

    lo = 1, hi = n;
    while(lo <= hi){
        mid = (lo+hi)/2;
        query(1,x3,mid,x4);
        cin>>a;

        if(a == 0){
            lo = mid+1;
        }else{
            hi = mid-1;
            y4 = min(y4, mid);
        }
    }

    lo = 1, hi = n;
    while(lo <= hi){
        mid = (lo+hi)/2;
        query(mid,x1,n,x2);
        cin>>a;

        if(a == 0){
            hi = mid-1;
        }else{
            lo = mid+1;
            y1 = max(y1, mid);
        }
    }

    if(topdown){
        if(y1 == y3){
            y1 = 1;
            lo = 1, hi = n;
            while(lo <= hi){
                mid = (lo+hi)/2;
                query(mid,x1,n,x2);
                cin>>a;

                if(a <= 1){
                    hi = mid-1;
                }else{
                    lo = mid+1;
                    y1 = max(y1, mid);
                }
            }

            lo = 1, hi = n;
            while(lo <= hi){
                mid = (lo+hi)/2;
                query(1,x1,mid,x2);
                cin>>a;

                if(a == 0){
                    lo = mid+1;
                }else{
                    hi = mid-1;
                    y2 = min(y2, mid);
                }
            }
        }else{
            lo = 1, hi = n;
            while(lo <= hi){
                mid = (lo+hi)/2;
                query(1,x1,mid,x2);
                cin>>a;

                if(a <= 1){
                    lo = mid+1;
                }else{
                    hi = mid-1;
                    y2 = min(y2, mid);
                }
            }
        }
    }else{
        lo = 1, hi = n;
        while(lo <= hi){
            mid = (lo+hi)/2;
            query(1,x1,mid,x2);
            cin>>a;

            if(a == 0){
                lo = mid+1;
            }else{
                hi = mid-1;
                y2 = min(y2, mid);
            }
        }
    }

    cout << "! " << y1 << " " << x1 << " " << y2 << " " << x2 << " " << y3 << " " << x3 << " " << y4 << " " << x4 << endl;

    return 0;
}