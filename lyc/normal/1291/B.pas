var t,i1,n,i:longint;ans:boolean;a:array[0..300000]of longint;bl,bl1:array[0..300000]of boolean;
begin
  readln(t);
  for i1:=1 to t do
  begin
    readln(n);ans:=false;bl[0]:=false;bl1[n+1]:=false;
    for i:=1 to n do
    begin
      read(a[i]);
      bl[i]:=bl[i-1];
      if (bl[i]=false)and((a[i]<i-1)and(i<>1)) then bl[i]:=true;
    end;
    for i:=n downto 1 do
    begin
      bl1[i]:=bl1[i+1];
      if (bl1[i]=false)and((a[i]<(n-i+1)-1)and(i<>n)) then bl1[i]:=true;
      if (bl[i]=false)and(bl1[i]=false) then
      begin
        ans:=true;
        break;
      end;              
    end;
    if ans then writeln('Yes') else writeln('No');
  end;
end.