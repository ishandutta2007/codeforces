var n,i:longint;s:longint;
begin
  readln(n,s);
  if (s-2*(n-1)<=1)or(s-2*(n-1)=s-1) then writeln('NO') else
  begin
    writeln('YES');
    for i:=1 to (n-1) div 2 do write(2,' ',2,' ');
    if n mod 2=0 then write(2,' ');
    writeln(s-2*(n-1));
    writeln(1);
  end;
end.