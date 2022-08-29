#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

int main(){
//  freopen("input.txt","rt",stdin);
//  freopen("output.txt","wt",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        int s,f,t;
        cin>>s>>f>>t;
        int t1=t%((m-1)*2)+1;
        if (s==f) cout<<t<<endl;
        else
        if (s>=t1)
        {
            //t++;
            //t--;
            if (f>s)
            {
                    //cout<<"-1";
                cout<<t-t1+f<<endl;
            }
            else
            {   
                //cout<<"-2";
                cout<<t-t1+1+m-1+m-f<<endl;
            }
        }
        else
        {
            if (m+m-s>=t1)
            {
                    
                if (f<s)
                {
                    //cout<<"-3";
                    cout<<t-t1+1+m-1+m-f<<endl;
                }
                else
                {
                    //cout<<"-4";
                    cout<<t-t1+2*(m-1)+f<<endl;
                }
            }
            else
            {
                if (f>s)
                {
                    //cout<<"-5";
                    cout<<t-t1+2*(m-1)+f<<endl;
                }
                else
                {
                    //cout<<"-6";
                    cout<<t-t1+1+3*(m-1)+m-f<<endl;
                }
            }
        }
    }
   return 0; 
}