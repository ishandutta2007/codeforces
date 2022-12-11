program project1;

var
   kz : char;
   m1,m2,z1,z2 : char;
begin
     readln(kz);
     read(z1);
     read(m1);
     read(z2);
     read(z2);
     read(m2);
     if z1 = 'Q' then z1:='b';
     if z1 = 'J' then z1:='a';
     if z1 = 'K' then z1:='c';
     if z1 = 'A' then z1:='d';
     if z2 = 'Q' then z2:='b';
     if z2 = 'J' then z2:='a';
     if z2 = 'K' then z2:='c';
     if z2 = 'A' then z2:='d';
     if (m1 = m2) then begin
        if z1 > z2 then writeln('YES') else writeln('NO');
        halt(0);
     end;
     if (m1 = kz) and (m2 <> kz) then begin
        writeln('YES');
        halt(0);
     end;
     if (m1 <> kz) and (m2 = kz) then begin
        writeln('NO');
        halt(0);
     end;
     if (m1 <> kz) and (m2 = kz) then begin
        if z1 > z2 then writeln('YES') else writeln('NO');
        halt(0);
     end;
     if (m1 <> kz) and (m2 <> kz) then begin
        writeln('NO');
        halt(0);
     end;
end.