var n,m,a,b,c:int64;
begin
    read(m,n,a);
    case m mod a of 
        0:b:=m div a;
        else b:=(m div a)+1;
    end;
    case n mod a of
        0:c:=n div a;
        else c:=(n div a)+1;
    end;
    c:=c*b;
    write(c);
    readln
end.