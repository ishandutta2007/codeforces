#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

string ss[2] = {"NO","YES"};

void ask(int n) {
    cout<<"? "<<n<<'\n';
    fflush(stdout);
}

int main() {
    int n; cin>>n;
    //First, binary search for answer for 1 row
    int mini = n, maxi = 5e6;
    while(mini < maxi) {
        int md = mini + maxi >> 1;
        if(md == mini) {
            ask(mini);
            int a; cin>>a;
            if(a != 1)
                mini = maxi;
            else
                maxi = mini;
        }
        else {
            ask(md);
            int a; cin>>a;
            if(a != 1)
                mini = md;
            else
                maxi = md;
        }
    }
    int sum = mini;
    int ans = sum;
    //For each k, there is only one candidate
    for(int i=2;i<=n;i++) {
        int can = sum/i;
        ask(can);
        int a; cin>>a;
        if(a != i) continue;
        ans = min(can * i,ans);
    }
    cout<<"! "<<ans<<'\n';
    fflush(stdout);
    return 0;
}