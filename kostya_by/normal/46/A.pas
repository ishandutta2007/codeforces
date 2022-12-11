program project1;

var
i,ans,n:longint;
begin
     readln(n);
     ans:=1;
     for i:=1 to n-1 do begin
         ans:=ans+i;
         if ans>n then ans:=ans - n;
         write(ans,' ');
     end;
end.