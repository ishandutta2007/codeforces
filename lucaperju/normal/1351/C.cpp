#include <bits/stdc++.h>

using namespace std;
char v[100005];
map<long long,int>mpu;
map<long long,int>mpr;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long m,n,i,t,j,k,mx,p,mxx=0,a;
    cin>>t;
    while(t--)
    {
        cin>>v;
        long long s=0;
        n=strlen(v);
        long long pzc=0;
        for(i=0;i<n;++i)
        {
            if(v[i]=='N')
            {
                if(mpu[pzc])
                    s+=1;
                else
                    s+=5;
                mpu[pzc]=1;
                pzc-=1000000;
            }
            if(v[i]=='S')
            {
                if(mpu[pzc+1000000])
                    s+=1;
                else
                    s+=5;
                pzc+=1000000;
                mpu[pzc]=1;
            }
            if(v[i]=='E')
            {
                if(mpr[pzc])
                    ++s;
                else
                    s+=5;
                mpr[pzc]=1;
                ++pzc;
            }
            if(v[i]=='W')
            {
                if(mpr[pzc-1])
                    ++s;
                else
                    s+=5;
                --pzc;
                mpr[pzc]=1;
            }
        }
        pzc=0;
        mpu[0]=0;
        mpr[0]=0;
        for(i=0;i<n;++i)
        {
            if(v[i]=='N')
                pzc-=1000000;
            if(v[i]=='S')
                pzc+=1000000;
            if(v[i]=='E')
                ++pzc;
            if(v[i]=='W')
                --pzc;
            mpu[pzc]=0;
            mpr[pzc]=0;
        }
        cout<<s<<'\n';
    }
    return 0;
}