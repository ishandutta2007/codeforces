/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdio>

#define Pi M_PI

using namespace std;

typedef long long ll;
typedef long double ldb;

int Query;

struct node{
    ll X,Y;

    node (ll _X=-1, ll _Y=-1) : X(_X), Y(_Y) {}

    inline bool operator == (const node &sec) const{
        return X==sec.X && Y==sec.Y;
    }

    inline node operator - (const node &sec) const{
        return node(X-sec.X, Y-sec.Y);
    }
        
    inline ll operator ^ (const node &sec) const{
        return X*sec.Y - Y*sec.X;
    }

    inline void read(){
        int x,y;
        scanf ("%d%d", &x, &y);
        X=(ll)x, Y=(ll)y;
    }


}a1,a2,b1,b2,c1,c2;
/*********************************/
inline void write(node &v){
    cout << '(' << v.X << ',' << v.Y << ')' << ' ' ;
}
/*********************************/
inline ll dis (node v){
    return v.X*v.X + v.Y*v.Y;
}
/*******************************/
inline bool inside(node &a, node &e1, node &e2){
    if (((a-e1)^(a-e2))!= 0ll)
        return false;
    
    ll ae1 = dis(a-e1); 
    ll ae2 = dis(a-e2);
    ll e1e2= dis(e1-e2);
    if ((ae1*ae2==0) || e1e2<=max(ae1,ae2))
        return false;
    if (min(ae1,ae2)*16 < max(ae1,ae2))
        return false;
    return true;
}
/*******************************/
inline bool check (){
    if (a2==b2 || a2==b1)
        swap(a1,a2);
    if (a1==b2)
        swap(b1,b2);
    if (!(a1==b1))
        return false;

    if (dis(a1-a2)+dis(a1-b2) < dis(a2-b2))
        return false;
    if (((b2-a1)^(b2-a2))==0)
        return false;
    if (((c1-b1)^(c1-b2))== 0ll)
        swap (c1,c2);
    return inside(c1,a1,a2) && inside(c2,b1,b2);
}
/********************************/
int main (){
    cin >> Query;
    for (int i=1;i<=Query;i ++){
        
        a1.read(); a2.read();
        b1.read(); b2.read();
        c1.read(); c2.read();

        bool flag= false;
        for (int j=1;j<=3;j++){
            flag= check ();
            if (flag)
                break;
            swap (a1,b1); swap(a2,b2);
            swap (b1,c1); swap(b2,c2);
        }
        flag ? puts("YES") : puts("NO");
    }
    return 0;
}