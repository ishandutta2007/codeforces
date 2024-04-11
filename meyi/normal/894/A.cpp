#include<cstdio>
#include<cstring>
#define ri register int
char a[101];
main(){
	scanf("%s",a);
	int l=strlen(a),s=0;
	for(ri i=0;i<l;++i)
		if(a[i]=='Q')
			for(ri j=i+1;j<l;++j)
				if(a[j]=='A')
					for(ri k=j+1;k<l;++k)
						if(a[k]=='Q')
							++s;
	printf("%d",s);
}