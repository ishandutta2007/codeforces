u,v=map(int,input().split())
if v<u:
    print(-1)
elif u==v and u==0:
    print(0)
elif u==v:
    print(1)
    print(u)
else:
    if u%2==v%2:
    #    x=bin((v-u)//2+u)[2:][-1::-1]
      #  j=0
        if(((v-u)//2)+u)^((v-u)//2)==u:
            print(2)
            print((v-u)//2+u,(v-u)//2)
            
        else:
            print(3)
            print(u,(v-u)//2,(v-u)//2)
    else:
        print(-1)
        
##        st=1
##        stt=0
##        while st<=v*10:
##            if (u^st)+(((v-u)//2)^st)+((v-u)//2)==v:
##                stt=1
##                break
##            st*=2
##        
##        if(stt==1):
##            print(3)
##            print((u^st),(((v-u)//2)^st),((v-u)//2))
##        else:
##            print(u,u,u)
##