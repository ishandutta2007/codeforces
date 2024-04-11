program project1;

var
i,n,sum:longint;
begin
     readln(n);
     sum:=0;
     for i:=1 to 500 do begin
         if sum<n then inc(sum,i);
     end;
     if sum=n then writeln('YES') else writeln('NO');
end.