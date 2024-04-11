program project1;

var
   h1,h2,m1,m2,p : longint;
   c1,c2,c3,c4 : char;

procedure next;
begin
     inc(m2);
     if m2 > 9 then begin
        m2:=0;
        inc(m1);
     end;
     if m1 > 5 then begin
        m1:=0;
        inc(h2);
     end;
     if (h2 > 9) or ((h2 > 3) and (h1 = 2)) then begin
        h2:=0;
        inc(h1);
     end;
     if h1 > 2 then begin
        m2:=0;
        m1:=0;
        h1:=0;
        h2:=0;
     end;
end;

begin
     read(c1);
     read(c2);
     read(c3);
     read(c3);
     read(c4);
     val(c1,h1,p);
     val(c2,h2,p);
     val(c3,m1,p);
     val(c4,m2,p);
     next;
     while true do begin
           if (h1 = m2) and (h2 = m1) then begin
              writeln(h1,h2,':',m1,m2);
              halt(0);
           end;
           next;
     end;
end.