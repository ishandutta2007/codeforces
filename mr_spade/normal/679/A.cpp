#include<cstdio>
int book;
int prime[20]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
char res[10];
signed main()
{
  register int i;
  for(i=1;i<=15;++i)
  {
    printf("%d\n",prime[i]);
    fflush(stdout);
    scanf("%s",res);
    if(res[0]=='y')
      if(book)
        return puts("composite"),0;
      else
        book=i;
  }
  if(!book||book>4)
    return puts("prime"),0;
  printf("%d\n",prime[book]*prime[book]);
  fflush(stdout);
  scanf("%s",res);
  puts(res[0]=='y'?"composite":"prime");
  return 0;
}