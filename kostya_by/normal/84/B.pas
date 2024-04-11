program project1;

var
   a : array[1..100010] of longint;
   ans,raz : int64;
   h,t,i,n : longint;
begin
     ans:=0;
     read(n);
     for i:=1 to n do read(a[i]);
     a[n + 1]:=maxlongint;
     h:=1;
     t:=1;
     while h <> n+1 do begin
           while a[h] = a[t] do inc(t);
           dec(t);
           raz:=t - h + 1;
           ans:=ans + (raz * (raz + 1) div 2);
           h:=t + 1;
           t:=t + 1;
     end;
     writeln(ans);
end.