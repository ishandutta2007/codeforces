#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        int n,i,ans=0,k,ham=0;
        bool sing=true;
        string s;
        int look[30];
        for(i=0;i<30;i++)
            look[i]=0;
        cin>>n>>k;
        cin>>s;
        for(i=0;i<n;i++)
        {
            look[s.at(i)-'a']++;
            if(look[s.at(i)-'a']==1)
                ham++;
        }
        if(ham>=2)
            sing = false;
        bool first=true,late=false,nprint=false,ham2suc=false;
        for(i=0;i<28;i++)
        {
            if(late)
            {
                int cur = look[i];
                while(cur--)
                {
                    char ss=i+'a';
                    cout<<ss;
                }
                look[i]=0;
                continue;
            }

            if(ham==1)
            {
                int prin = look[i];
                while(look[i]>0)
                {
                    char ss = i+'a';
                    cout<<ss;
                    look[i]-=k;
                }
                continue;
            }

            if(look[i]==k && ham==2 && first)
            {
                char ss = i+'a';
                cout<<ss;
                look[i]=0;
                first = false;
                ham2suc=true;
                continue;
            }

            if(ham == 2 && ham2suc)
            {
                int prin = look[i];
                while(look[i]>0)
                {
                    char ss = i+'a';
                    cout<<ss;
                    look[i]-=k;
                }
                continue;
            }

            if(first && look[i]<k && look[i]!=0)
            {
                first = false;
                nprint=true;
                break;
            }

            if(first && look[i]>=k)
            {
                first = false;
                look[i]-=k-1;
                late=true;
                i--;
                continue;
            }
        }
        int curr=0,last =-1;
        if(nprint)
        {
            for(i=0;i<28;i++)
            {
                curr+=look[i];
                if(look[i]>0)
                {
                    last = look[i];
                }
                if(curr>=k)
                {
                    char ss = i+'a';
                    cout<<ss;
                    nprint = false;
                    break;
                }
            }
            if(nprint)
            {
                if(last!=-1)
                {
                    char ss = last + 'a';
                    cout<<ss;
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}