#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--) {
        int n,m;
        cin>>n>>m;
        string s[n];
        for(int i=0;i<n;i++)
            cin>>s[i];
        char b[n][m];
        bool pass = true;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                char cur;
                if((i+j)%2 == 0)
                    cur = 'R';
                else
                    cur = 'W';

                if(cur != s[i][j] && s[i][j] != '.')
                    pass = false;
            }
        }
        if(pass) {
            cout<<"YES\n";
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    char cur;
                    if((i+j)%2 == 0)
                        cur = 'R';
                    else
                        cur = 'W';
                    cout<<cur;
                }
                cout<<"\n";
            }
            continue;
        }
        pass = true;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                char cur;
                if((i+j)%2 == 0)
                    cur = 'W';
                else
                    cur = 'R';

                if(cur != s[i][j] && s[i][j] != '.')
                    pass = false;
            }
        }
        if(pass) {
            cout<<"YES\n";
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    char cur;
                    if((i+j)%2 == 0)
                        cur = 'W';
                    else
                        cur = 'R';
                    cout<<cur;
                }
                cout<<"\n";
            }
            continue;
        }
        cout<<"NO\n";
    }
    return 0;
}