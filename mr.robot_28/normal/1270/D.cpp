#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n, k;
    cin>>n>>k;
    vector<int> elements;
    for (int i = 1; i<=k+1; i++)
    {
        cout<<"? ";
       
        for (int j = 1; j<=k+1; j++) if (j!=i) cout<<j<<' ';
        cout<<endl;
       
        int pos, el;
        cin>>pos>>el;
        elements.push_back(el);
    }
    int maxx = elements[0];
    for (auto it: elements) maxx = max(maxx, it);
    int m = 0;
    for (auto it: elements) if (it==maxx) m++;
    cout<<"! "<<m<<endl;
 
}