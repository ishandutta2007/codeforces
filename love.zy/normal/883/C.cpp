#include<bits/stdc++.h>  
typedef long long ll;  
using namespace std;  
  
int main()  
{  
    ll f,t,t0,a1,t1,p1,a2,t2,p2,i,j;  
    ll tt,ff,minn=1e18;  
    
	cin>>f>>t>>t0>>a1>>t1>>p1>>a2>>t2>>p2;  
    if(t1>t2)  
        swap(t1,t2),swap(a1,a2),swap(p1,p2);  // ngam dinh goi cuoc co toc do tai nhanh la goi bo sung 1
  
    for(i=0;a1*i<f;i++)  // i la so goi 1 can mua
    {  
        ff=f-i*a1;      // sau khi tai bang i goi 1, tinh dung luong con lai.
        tt=t-i*a1*t1;  // va thoi gian con lai.
        if(ff*t2>tt && ff*t0>tt)  // Phan dung luong con lai, Neu 2 goi kia deu khong co kha nang tai kip gio
        continue;                 // thi tiep tuc mua goi 1
        if(t0<=t2 || ff*t0<=tt) j=0;  // Neu goi thuong tai kip gio hoac no tai nhanh hon goi 2 thi khong mua goi 2
        else {							// nguoc lai, tinh j la so goi 2 can mua:
		    //j=((t0*ff-tt+t0-t2-1)/(t0-t2)+a2-1)/a2;
		    j = (ff*t0 - tt)/(a2*(t0-t2));
		    if ((j*a2*t2 + (ff-j*a2)*t0)>tt)j++;
		}  												
                                                      // so byte tai bang goi 2 la j*a2
                                                      // so byte tai bang goi thuong la (ff-j*a2)
                                                      // thoi gian tai bang goi 2 la: j*a2*t2
                                                      // thoi gian tai bang goi thuong la: (ff-j*a2)*t0
													  // ta phai co: j*a2*t2 + (ff-j*a2)*t0 <= tt
													  // hay ff*to - tt <= j*a2*(t0-t2)
													  // j >= (ff*t0 - tt)/(a2*(t0-t2))
        if(p1*i+p2*j<minn) minn=p1*i+p2*j;  
    }  
    if(f*t1<=t && (f+a1-1)/a1*p1<minn) minn=(f+a1-1)/a1*p1;  
    if(minn==1e18)  
       // printf("%d\n",-1);
        cout<<-1;
    else  
       // printf("%lld\n",minn);  
        cout<<minn;
    return 0;  
}