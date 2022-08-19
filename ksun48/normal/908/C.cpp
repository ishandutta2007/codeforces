#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int n;
    int r;
    cin >> n >> r;
    vector<pair<int,double> > p;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        double yc = r;
        for(int j = 0; j < p.size(); j++){
            if(abs(p[j].first - a) > 2*r) continue;
            double d = sqrt((double)(2.0*r*2.0*r) - (p[j].first - a)*(p[j].first - a));
            yc = max(yc, p[j].second + d);
        }
        p.push_back(make_pair(a, yc));
        printf("%.10lf ", yc);
    }
    cout << endl;
}