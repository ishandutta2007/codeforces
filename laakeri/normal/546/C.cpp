#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    deque<int> p1;
    deque<int> p2;
    int k1;
    cin>>k1;
    for (int i=0;i<k1;i++){
        int a;
        cin>>a;
        p1.push_back(a);
    }
    int k2;
    cin>>k2;
    for (int i=0;i<k2;i++){
        int a;
        cin>>a;
        p2.push_back(a);
    }
    for (int i=0;i<50000000;i++){
        if (p1.size()==0){
            cout<<i<<" "<<2<<endl;
            return 0;
        }
        if (p2.size()==0){
            cout<<i<<" "<<1<<endl;
            return 0;
        }
        int t1=p1.front();
        int t2=p2.front();
        p1.pop_front();
        p2.pop_front();
        if (t1>t2){
            p1.push_back(t2);
            p1.push_back(t1);
        }
        else{
            p2.push_back(t1);
            p2.push_back(t2);
        }
    }
    cout<<-1<<endl;
}