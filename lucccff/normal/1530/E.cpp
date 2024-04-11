#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,x,y,z;
    long long a[30];
    pair <long long,char> p[30],q;
    string s;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>s;
        n=s.length();
        memset(a,0,sizeof(a));
        for(j=0;j<n;j++) {
            a[s[j]-'a']++;
        }
        for(j=0;j<26;j++) {
            p[j]=make_pair(a[j],char(j+'a'));
        }
        sort(p,p+26);
        k=p[25].first;
        if (k==n) {
            for(j=0;j<n;j++) {
                cout<<s[0];
            }
            cout<<endl;
            continue;
        }
        j=0;
        while(p[j].first==0) j++;
        if (p[j].first==1) {
            cout<<p[j].second;
            x=j;
            for(j=0;j<26;j++) {
                if (j!=p[x].second-'a') for(k=0;k<a[j];k++) {
                    cout<<(char)(j+'a');
                }
            }
            cout<<endl;
            continue;
        }
        if (j<=23) {
            for(j=0;j<26;j++) {
                if (a[j]!=0) {
                    x=j;
                    break;
                }
            }
            if (a[x]-2>n-a[x]) {
                for(j=0;j<26;j++) {
                    if (a[j]!=0&&x!=j) {
                        y=j;
                        break;
                    }
                }
                cout<<char(x+'a');
                cout<<char(y+'a');
                a[x]--;
                a[y]--;
                for(j=0;j<a[x];j++) {
                    cout<<char(x+'a');
                }
                a[x]=0;
                for(j=0;j<26;j++) {
                    if (a[j]!=0&&x!=j&&y!=j) {
                        z=j;
                        break;
                    }
                }
                cout<<char(z+'a');
                a[z]--;
                for(j=0;j<26;j++) {
                    for(k=0;k<a[j];k++) {
                        cout<<(char)(j+'a');
                    }
                }
            }
            else {
                cout<<char(x+'a');
                cout<<char(x+'a');
                k=x+1;
                for(j=2;j<a[x];j++) {
                    while(a[k]==0) k++;
                    cout<<char(k+'a');
                    cout<<char(x+'a');
                    a[k]--;
                }
                while(k<26) {
                    while(k<26&&a[k]==0) k++;
                    if (k==26) break;
                    cout<<char(k+'a');
                    a[k]--;
                }
            }
            /*if (a[x]!=1) {
                for(j=0;j<26;j++) {
                    if (a[j]!=0&&x!=j) {
                        y=j;
                        break;
                    }
                }
                for(j=0;j<26;j++) {
                    if (a[j]!=0&&x!=j&&y!=j) {
                        z=j;
                        break;
                    }
                }
                cout<<char(x+'a');
                cout<<char(y+'a');
                cout<<char(z+'a');
                a[x]--;
                a[y]--;
                a[z]--;
            }
            else {
                for(j=0;j<26;j++) {
                    if (a[j]!=0) {
                        x=j;
                        break;
                    }
                }
                cout<<char(x+'a');
                a[x]--;
            }
            for(j=0;j<26;j++) {
                for(k=0;k<a[j];k++) {
                    cout<<(char)(j+'a');
                }
            }*/

            /*cout<<p[j].second;
            cout<<p[j+1].second;
            x=j;
            for(j=j+2;j<26;j++) {
                for(k=0;k<p[j].first;k++) {
                    cout<<p[j].second;
                }
            }
            for(k=1;k<p[x].first;k++) {
                cout<<p[x].second;
            }
            for(k=1;k<p[x+1].first;k++) {
                cout<<p[x+1].second;
            }*/
            cout<<endl;
            continue;
        }
        else {
            if (p[25].second>p[24].second) {
                q=p[24];
                p[24]=p[25];
                p[25]=q;
            }
            k=p[25].first;
            l=(k-2)/(n-k+1)+2;
            if (l>=3) {
                cout<<p[25].second;
                for(j=0;j<p[24].first;j++) {
                    cout<<p[24].second;
                }
                for(j=1;j<p[25].first;j++) {
                    cout<<p[25].second;
                }
            }
            else {
                for(j=0;j<l;j++) {
                    cout<<p[25].second;
                }
                k=k-l;
                l=p[24].first;
                while(l) {
                    cout<<p[24].second;
                    for(j=0;j<(k+l-1)/l;j++) cout<<p[25].second;
                    k-=(k+l-1)/l;
                    l--;
                }
            }
            cout<<endl;
        }
    }
    return 0;
}