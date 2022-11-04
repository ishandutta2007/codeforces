/*#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n , k , p , t;
char a[50][3] , f[50];

int main ()
{
	int i , j;
	cin >> n >> k;
	for (i = 0 ; i < n-k+1 ; i++)
	    cin >> a[i];
	f[0] = 'a';    
	for (i = 1 ; i < 26 ; i++)
		f[i] = f[i-1]+1;
	f[26] = 'A';    
	for (i = 27 ; i < 50 ; i++)
		f[i] = f[i-1]+1;
	if (a[0][0] == 'Y')
	{
		cout << f[0];
		for (i = 1 ; i < k ; i++)
		    cout << " " << f[i];
	}
	else
	{
		cout << f[1] << " " << f[1];
		for (i = 2 ; i < k ; i++)
		    cout << " " << f[i];
	} 
	for (i = 1 ; i < n-k+1 ; i++)
	{
		if (a[i][0] == 'Y')
		    cout << " " << f[i+k-1];
		else
		    cout << " " << f[i];   
	}
	cout << "\n";
	//system("PAUSE");
	return 0;
}*/
#include<stdio.h>  
#include<string.h>  
using namespace std;  
int ans[55];  
char a[55][55];  
int main()  
{  
    char name[1005][55];  
    char fst='A';  
    char sec='a';  
    for(int i=1;i<=1000;i++)  
    {  
        for(int j=0;j<2;j++)  
        {  
            if(j==0)name[i][j]=fst;  
            else name[i][j]=sec,sec++;  
            if(sec>'z')fst++,sec='a';  
        }  
        name[i][2]='\0';  
    }  
    int n,k;  
    while(~scanf("%d%d",&n,&k))  
    {  
        int now=1;  
        memset(ans,-1,sizeof(ans));  
        for(int i=0;i<n-k+1;i++)  
        {  
            scanf("%s",a[i]);  
            if(strcmp(a[i],"YES")==0)  
            {  
                for(int j=i;j<i+k;j++)  
                {  
                    ans[j]=now;  
                    now++;  
                }  
            }  
        }  
        for(int i=0;i<n;i++)  
        {  
            if(ans[i]==-1)ans[i]=now,now++;  
        }  
        for(int i=0;i<n-k+1;i++)  
        {  
            if(strcmp(a[i],"NO")==0)  
            {  
                ans[i+k-1]=ans[i];  
            }  
        }  
        for(int i=0;i<n;i++)  
        {  
            printf("%s ",name[ans[i]]);  
        }  
        printf("\n");  
    }  
}