#include<bits/stdc++.h>

using namespace std;

const int maxi=5e5+10;
int l[maxi],r[maxi];
int n;
string s,t;
vector<int> v[maxi];
int pref[26][maxi];
int main()
{
    cin>>s;
    cin>>t;

    int cur = - 1;
    int n = t.size();

    for (int i=0; i<s.size(); i++)
        if (cur<n-1 && t[cur+1]==s[i])
            l[i]=++cur;
        else
            l[i]=cur;

    cur = n;


    for (int i=s.size()-1; i>=0; i--)
        if (cur>0 && t[cur-1]==s[i])
            r[i]=--cur;
        else
            r[i]=cur;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<26; j++)
            if (i>0)
                pref[j][i]=pref[j][i-1];
        pref[t[i]-'a'][i]++;
    }

    for (int i=0; i<s.size(); i++)
    {
        int left, right;
        if (i==0)
            left = -1;
        else
            left = l[i-1];

        if (i+1==s.size())
            right = n;
        else
            right = r[i+1];

        left++;
        right--;

        if (left<right)
            return !printf("No\n");

        left = pref[s[i]-'a'][min(left,n-1)];
        if (right<=0) right=0; else
            right = pref[s[i]-'a'][right-1];
        if (left-right==0) return !printf("No\n");

    }

    printf("Yes\n");

    return 0;
}