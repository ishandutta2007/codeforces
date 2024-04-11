var t,i1,l,r,sum,sum1,i,x,y,n:longint;bl:boolean;
begin
  read(t);
  for i1:=1 to t do
  begin
    read(n); bl:=false;
    l:=0;r:=0;sum:=0;sum1:=0;
    for i:=1 to n+1 do
    begin
      if i=n+1 then break;
      read(x,y);
      if ((x<l)or(y<r)or(y-r>x-l))and(not bl) then
      begin
        writeln('NO');
        bl:=true;
      end;
      l:=x;r:=y;
      if (r>l)and(not bl) then
      begin
        writeln('NO');
        bl:=true;
      end;
    end;
    if not bl then writeln('YES');
  end;
end.