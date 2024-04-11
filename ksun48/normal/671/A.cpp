#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    double ax, ay, bx, by, tx, ty;
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    int n;
    cin >> n;
    double x[n], y[n];
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    double da[n];
    double db[n];
    double ans = 0;
    for(int i = 0; i < n; i++){
        ans += 2.0*sqrt((x[i]-tx)*(x[i]-tx) + (y[i]-ty)*(y[i]-ty));
    }
    for(int i = 0; i < n; i++){
        da[i] = sqrt((x[i]-ax)*(x[i]-ax) + (y[i]-ay)*(y[i]-ay));
        da[i] -= sqrt((x[i]-tx)*(x[i]-tx) + (y[i]-ty)*(y[i]-ty));
        db[i] = sqrt((x[i]-bx)*(x[i]-bx) + (y[i]-by)*(y[i]-by));
        db[i] -= sqrt((x[i]-tx)*(x[i]-tx) + (y[i]-ty)*(y[i]-ty));
    }
    int besta = 0;
    int bestb = 0;
    for(int j = 0; j < n; j++){
        if(da[j] < da[besta]) besta = j;
        if(db[j] < db[bestb]) bestb = j;
    }
    double best = min(da[besta], db[bestb]);
    for(int j = 0; j < n; j++){
        if(j != besta){
            best = min(best, da[besta] + db[j]);
        }
        if(j != bestb){
            best = min(best, da[j] + db[bestb]);
        }
    }
    printf("%.10lf\n", best + ans);
}