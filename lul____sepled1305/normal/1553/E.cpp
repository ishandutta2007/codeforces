#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--) {
        int n,m;
        cin>>n>>m;
        int a[n], b[n], inv[n];
        for(int i=0;i<n;i++)
            cin>>a[i], b[i] = 0, inv[a[i]-1] = i;
        for(int i=0;i<n;i++) {
            int k = ((i-a[i]+1)+n)%n;
            b[k]++;
        }
        vector<int> v;
        for(int i=0;i<n;i++) {
            if(b[i] + 2*m >= n)
                v.push_back(i);
        }
        vector<int> w;
        //let's hope v is not too big (I guess)
        for(auto it: v) {
            //Compute permu
            //cout<<"F "<<it<<endl;
            int r[n], p[n];
            bool vv[n];
            for(int i=0;i<n;i++) {
                r[(i+it)%n] = i;
            }
            for(int i=0;i<n;i++) {
                p[i] = inv[r[i]];
                vv[i] = false;
                //cout<<r[i]<<' ';
            }
            //cout<<endl;
            //Do cycle decomp
            int cyc = 0;
            for(int i=0;i<n;i++) {
                int runner = i;
                if(vv[i] == false) {
                    cyc++;
                    while(!vv[runner]) {
                        vv[runner] = true;
                        runner = p[runner];
                    }
                }
            }
            //cout<<cyc<<endl;
            if(n-cyc <= m)
                w.push_back(it);
        }
        cout<<w.size()<<' ';
        for(auto it: w)
            cout<<it<<' ';
        cout<<endl;
    }
    return 0;
}