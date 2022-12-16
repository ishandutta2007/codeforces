var c:array[-300000..300000,0..1,0..1]of longint;mr,ml,sll,sl,i,j,n,cl,cr:longint;ans:int64;
    s:ansistring;
begin
  readln(n);
  for i:=1 to n do
  begin
    readln(s);
    sl:=0;
    mr:=0; ml:=0;
    for j:=1 to length(s) do
    begin
      if s[j]='('then
      begin
        inc(sl);
      end
      else if s[j]=')'then begin
        dec(sl);
      end;
       if sl<mr then mr:=sl;
    end;
    sll:=0;
    for j:=length(s)downto 1 do
    begin
      if s[j]='('then
      begin
        inc(sll);
      end
      else if s[j]=')'then begin
        dec(sll);
      end;
       if sll>ml then ml:=sll;
    end;
    if mr<0 then cl:=0 else cl:=1;
    if ml>0 then cr:=0 else cr:=1;
    //writeln(sl,' ',cl,' ',cr);
    inc(c[sl,cl,cr]);
    ans:=ans+(c[-sl,1,0])*cr;
    ans:=ans+(c[-sl,0,1])*cl;
    ans:=ans+(c[-sl,1,1])*(cl+cr);
    if(cl=1)and(cr=1)and(sl=0)then ans:=ans-1;
    //writeln(ans);
  end;
  writeln(ans);
end.