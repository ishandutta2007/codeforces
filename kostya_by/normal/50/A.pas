program project1;

var
   m,n,ans : longint;
begin
     readln(n,m);
     if (n mod 2 = 0) and  (m mod 2 = 0) then begin
        ans:=(m div 2) * n;
     end;
     if (n mod 2 = 0)  and (m mod 2 = 1) then begin
        ans:=(n div 2) * m;
     end;
     if (n mod 2 = 1) and  (m mod 2 = 0) then begin
        ans:=(m div 2) * n;
     end;
     if (n mod 2 = 1)  and (m mod 2 = 1) then begin
        dec(m);
        ans:=(m div 2) * n;
        ans:= ans + (n div 2);
     end;
     writeln(ans);
end.