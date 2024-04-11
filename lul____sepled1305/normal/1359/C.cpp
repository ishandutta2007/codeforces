/*Tiat love fake binary search.*/
#include<bits/stdc++.h>
using namespace std;
int t;
 
double form(int cup,double h, double c)
{
    double cu = (double) cup;
    return ((h*(2*cu+2))-c)/(2*cu+1);
}
 
/*int b_search(double h, double c, double tar)
{
    int maxi = 1e9, mini = 0;
    double half  = (h+c)/2;
    while(mini<maxi)
    {
        if(maxi==mini+1)
        {
            if(form(mini,half,c)<=tar)
                maxi = mini;
            else
                mini = maxi;
        }
        else
        {
            int mid = (mini+maxi)/2;
            if(form(mid,half,c)<=tar)
                maxi = mid;
            else
                mini = mid+1;
        }
    }
    return mini;
}*/
 
int main()
{
    cin>>t;
    while(t--)
    {
        double h,c,tar;
        cin>>h>>c>>tar;
        double half = (h+c)/2;
        if(tar <= half )
            cout<<2<<"\n";
        else if (tar >= h)
            cout<<1<<"\n";
        else
        {
            double A = (tar-c)/(h-c);
            A = (1-A)/(2*A-1);
            int ans = (int) floor(A);
            ans+=3;
            int i, fin= ans-6;
            for(i=ans-5;i<=ans+5;i++)
            {
                if(abs(tar - form(i,half,c)) < abs(tar - form(fin,half,c)))
                    fin = i;
            }
            if(fin<0)
                fin = 0;
            cout<<2*fin+1<<"\n";
        }
    }
    return 0;
}