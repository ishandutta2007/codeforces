#include<bits/stdc++.h>
using namespace std;
int tc;
int n,k;
char s[5000];
char t[5000];
vector<pair<int,int> > o;
int main() {
    scanf("%d",&tc);
    while(tc--) {
        scanf("%d %d",&n,&k);
        scanf("%s",s);
        for(int i=0;i<k-1;i++) {
            t[2*i]='(';
            t[2*i+1]=')';
        }
        int l=2*(k-1);
        int r=n/2-(k-1);
        while(r>0) {
            r--;
            t[l++]='(';
        }
        r=n/2-(k-1);
        while(r>0) {
            r--;
            t[l++]=')';
        }
        o.clear();
        for(int i=0;i<n;i++) {
            int j=i;
            while(s[j]!=t[i]) j++;
            //cout<<i<<" "<<j<<endl;
            o.push_back({i+1,j+1});
            for(int l=0;l<j-i-l;l++) swap(s[i+l],s[j-l]);
            //cout<<s<<endl;
        }
        printf("%d\n",o.size());
        for(int i=0;i<o.size();i++) printf("%d %d\n",o[i].first,o[i].second);
    }
    return 0;
}