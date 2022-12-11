#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3+5;

struct Point{
    int x,y;
    Point(int a, int b){
        x=a;
        y=b;
    }
};

bool cmp(Point a, Point b){
    if(a.x+a.y==b.x+b.y) return a.y<b.y;
    return a.x+a.y<b.x+b.y;
}

int n;
vector<Point> P1,P2;
int main()
{
    cin >> n;
    int x,y;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        P1.push_back(Point(x,y));
    }
    for(int i=0; i<n; i++){
        cin >> x >> y;
        P2.push_back(Point(x,y));
    }
    sort(P1.begin(),P1.end(),cmp);
    sort(P2.begin(),P2.end(),cmp);
    cout << P1[0].x+P2[n-1].x << ' ' << P1[0].y+P2[n-1].y;
}